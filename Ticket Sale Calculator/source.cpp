#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (fin.is_open())
	{
		const int size = 10;
		char ctgry[size], conti;
		int numsold[size] = { 0 }, price = 0, choice = -1, i = 0;
		fin.ignore(100, '\n');
		while (!fin.eof())
		{
			fin >> ctgry >> price;
			fin >> numsold[i];
			i++;
		}
		fin.close();
		do
		{
			cout << "1. Search the category with the maximum number of tickets sold" << endl;
			cout << "2. Search the category with the minimum number of tickets sold" << endl;
			cout << "3. Display only those categories whose total sales exceeds 10,000" << endl;
			cout << "4. Calculate total number of tickets sold" << endl;
			cout << endl;
			cout << "Input your desire option: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				int max = 0, index = 0;
				for (int j = 0; j < i; j++)
				{
					if (numsold[j] > max)
					{
						max = numsold[j];
						index = j;
					}
				}
				if (index == 0)
				{
					cout << "Category with Maximum Tickets Sold: Box " << endl;
				}
				else if (index == 1)
				{
					cout << "Category with Maximum Tickets Sold: Sideline " << endl;
				}
				else if (index == 2)
				{
					cout << "Category with Maximum Tickets Sold: Premium " << endl;
				}
				else
				{
					cout << "Category with Maximum Tickets Sold: General " << endl;
				}
				break;
			}
			case 2:
			{
				int min = 0, index = 0;
				for (int j = 0; j < i; j++)
				{
					if (min > numsold[j] || min == 0)
					{
						min = numsold[j];
						index = j;
					}
				}
				if (index == 0)
				{
					cout << "Category with minimum Tickets Sold: Box " << endl;
				}
				else if (index == 1)
				{
					cout << "Category with minimum Tickets Sold: Sideline " << endl;
				}
				else if (index == 2)
				{
					cout << "Category with minimum Tickets Sold: Premium " << endl;
				}
				else
				{
					cout << "Category with minimum Tickets Sold: General " << endl;
				}
				break;
			}
			case 3:
			{
				for (int j = 0; j < i; j++)
				{
					if (numsold[j] > 10000)
					{
						if (j == 0)
						{
							cout << "Box has total sales: " << numsold[j] << endl;
						}
						else if (j == 1)
						{
							cout << "Sideline has total sales: " << numsold[j] << endl;
						}
						else if (j == 2)
						{
							cout << "Premium has total sales: " << numsold[j] << endl;
						}
						else
						{
							cout << "General has total sales: " << numsold[j] << endl;
						}
					}
				}
				break;
			}
			case 4:
			{
				int sum = 0;
				for (int j = 0; j < i; j++)
				{
					sum = sum + numsold[j];
				}
				cout << "Total number of tickets sold: " << sum << endl;
				break;
			}
			default:
			{
				cout << "You have enter invalid choice" << endl;
			}
			}
			cout << endl;
			cout << "Do you want to continue (y/n): ";
			cin >> conti;
			cout << endl;
		} while (conti == 'y');
		cout << "You have exited the program" << endl;
	}
	else
	{
		cout << "File is not opened" << endl;
	}

	return 0;
}