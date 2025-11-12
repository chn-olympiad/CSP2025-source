#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],ans,b[105][105],ii=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[ii]==ans)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				else
				{
					ii++;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(a[ii]==ans)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				else
				{
					ii++;
				}
			}
		}
	}
	return 0;
}
