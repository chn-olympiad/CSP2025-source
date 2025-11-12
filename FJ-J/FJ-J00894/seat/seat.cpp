#include<bits/stdc++.h>
using namespace std;
int n,m,rs,a[105],wd,su=1,h,l,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rs=n*m;
	for(int i=1;i<=rs;i++)
	{
		cin>>a[i];
	}
	wd=a[1];
	for(int i=1;i<=rs;i++)
	{
		if(a[i]>wd)
		{
			su++;
		}
	}
	if(su<=n)
	{
		cout<<1<<" "<<su;
	}
	else
	{
		h=su%n;
		if(h==0)
		{
			l=su/n;
		}
		else
		{
			l=su/n+1;
		}
		if(l%2!=0)
		{
			if(h==0)
			{
				ans=n;
			} 
			else
			{
				ans=h;
			}
		}
		else
		{
			if(h==0)
			{
				ans=1;
			} 
			else
			{
				ans=n-h+1;
			}
		}
		cout<<l<<" "<<ans;
	}
	return 0;
}
