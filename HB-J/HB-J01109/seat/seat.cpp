#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,t,ans;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>a[1];
t=a[1];
for(int i=2;i<=n*m;i++)
	cin>>a[i];
int nn=n*m;
sort(a+1,a+1+nn);
for(int i=nn;i>=1;i--)
{
	if(a[i]==t)
	{
		ans=nn-i+1;
		break;
	}
}
int f=-1;
for(int i=1;i<=m;i++)
{
	if(f==-1)
	{
		for(int j=1;j<=n;j++)
		{
			ans--;
			if(ans==0)
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
			ans--;
			if(ans==0)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	f=f*(-1);
}
return 0;
}
