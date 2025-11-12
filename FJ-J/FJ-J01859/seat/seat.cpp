#include <bits/stdc++.h>
using namespace std;
int a[200],b[12][12];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	a1=a[1];
	sort(a+1,a+m*n+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(a[cnt]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(a[cnt]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
