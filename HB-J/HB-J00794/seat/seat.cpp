#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],mapn[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n*m;i++)
	{
		cin>>a[i];
	}
	int num = a[1];
	sort(a+1,a+n*m+1);
	int cnt = 1;
	for(int i = 1;i <= m;i++)
	{
		if(i%2 == 0)
		{
			for(int j = n;j >= 1;j--)
			{
				mapn[j][i] = a[cnt];
				cnt++;
				if(mapn[j][i] == num)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int j = 1;j <= n;j++)
			{
				if(a[cnt] == num)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(mapn[j][i] == num)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
