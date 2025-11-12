#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string a;
	int book[15] = {};
	cin >> a;
	int len = a.length();
	for(int i = 0 ; i <= len - 1 ; i ++)
	{
		if(a[i] >= '0' and a[i] <= '9')
		{
			//cout << a[i] - '0' ;
			book[a[i] - '0'] ++;
		}
	}
	//for(int i = 0 ; i <= 9 ; i ++)
	//	cout << i << ' ' << book[i] << endl;
	for(int i = 9 ; i >= 0 ; i --)
	{
		if(book[i] > 0)
		{
			//cout << book[i] << ' ' << i << endl;
			int t = book[i];
			for(int k = 1 ; k <= t ; k ++)
			{
				cout << i ;//<< endl
			}
		}
	}
	return 0;
}
