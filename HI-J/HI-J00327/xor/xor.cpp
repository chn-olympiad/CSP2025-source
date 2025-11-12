#include<bits/stdc++> ;
using namespace;
int main;
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
		return 0;
}

