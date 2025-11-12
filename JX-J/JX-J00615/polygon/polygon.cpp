#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],maxx=-INT_MAX,ans,sum;
void yangli_1()
{
	for(int i=1;i<=n;i++)
	{ cin>>a[i];maxx=max(maxx,a[i]);sum+=a[i];}
	if(sum>maxx*2)
	{
		cout<<1;
	}else
	{cout<<0;}
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3) 
	{yangli_1();}
	else
	{
		for(int i=1;i<=n;i++)
		{cin>>a[i];}
		for(int f=0;f<=n-3;f++)
		{
			for(int j=1;j<=n-f-1;j++)
			{
				sum=0;maxx=-INT_MAX;
				for(int i=j;i<=j+n-f-1;i++)
				{
					sum+=a[i];
					maxx=max(maxx,a[i]);
				}
				if(sum>maxx*2)
				{ans++;} 
			}
			
		}
		cout<<ans;
	}
	return 0;
}
