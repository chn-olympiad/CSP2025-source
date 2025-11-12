#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l = 0,r = 0;
	cin >> n;
	l = n/2;
	r = n/2+2;
	for(int i = 1;i <= n;i++)
	{
		if(i == 1 || i == n)
		{
			for(int j = 1;j <= n;j++)
			{
				if(j == n / 2 + 1)
				{
					cout << "#";
				}
				else
				{
					cout << ".";
				}
			}
			cout << endl;
		}
		else
		{
			for(int j = 1;j <= n;j++)
			{
				if(j == l || j == r)
				{
					cout << "#";
				}
				else
				{
					cout << ".";
				}
			}
			if(l == 1 && r == n)
			{
				l--;
				r++;
			}
			else
			{
				l++;
				r--;
			}
			cout << endl;
		}
	}
	return 0;
}
