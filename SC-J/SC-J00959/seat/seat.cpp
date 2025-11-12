#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],u,cnt;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		if(i == 1)
		{
			u = a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= m;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				cnt++;
				if(a[cnt] == u)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				cnt++;
				if(a[cnt] == u)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
} 