#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[50005];
int cheng;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if (n == 1 && m == 1)
	{
		cout<<"1 1";
		return 0;
	}
	else if(n == 1 && m <= 10 && m > 1)
	{
		for(int i = 1;i <= m;i ++)
		{
			cin>>a[i];
		}
		cheng = a[1];
		sort(a+1,a+m+1);
		for(int i = m,j = 1;i >= 1;i--,j++)
		{
			if(a[i] == cheng)
			{
				cout<<"1 "<<j;
				return 0;
			}
		}
	}
	else if(n<=10 && m == 1&& n > 1)
	{
		for(int i = 1;i <= n;i ++)
		{
			cin>>a[i];
		}
		cheng = a[1];
		sort(a+1,a+n+1);
		for(int i = n, j = 1;i>=1;i--,j ++)
		{
			if(a[i] == cheng)
			{
				cout<<j<<" 1";
				return 0;
			}
		}
	}
	return 0;
}
