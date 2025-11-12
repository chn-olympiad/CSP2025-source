#include <bits/stdc++.h>
using namespace std;
int m,n,num;
int a[200];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	int k = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1; j<=m; j++)
	{
		if(j%2==1)
		{
			for(int i=1; i<=n; i++)
			{
				num++;
				if(a[num] == k)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n; i>=1; i--)
			{
				num++;
				if(a[num] == k)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
 } 