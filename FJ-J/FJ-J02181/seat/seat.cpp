#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,ans;
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1);
	ans=n*m;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[ans]==t)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				else ans--;
			}
		}
		if(j%2==0)
		{
			for(int i=n;i>=1;i--)
			{
				if(a[ans]==t)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				else ans--;
			}
		}
	}
	return 0;	
} 
