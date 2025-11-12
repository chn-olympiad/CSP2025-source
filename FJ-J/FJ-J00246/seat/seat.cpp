#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105],n,m,self,position;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	self=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++)
	    if(a[i]==self)
	        position=i;
    ll now=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				if(now==position)
				{
				   cout<<i<<" "<<j;
				   return 0;	
				}
				now++;        
			}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(now==position)
				{
				   cout<<i<<" "<<j;
				   return 0;	
				}
				now++;
			}
		}
	}
	return 0;
}
