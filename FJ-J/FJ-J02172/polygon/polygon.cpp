#include<bits/stdc++.h>
using namespace std;
long long n,c[5010],x;
long long cba(long long xb,long long h,long long gs)
{
	if(gs==1)
	{
		if(c[xb]<h)
		  x++;
		x=x%998244353; 
	}
	else
	{
		if(xb+gs-1<=n)
		{
			for(long long i=xb+1;i<=n;i++)
			{
				cba(i,h+c[xb],gs-1);
				cba(i,h,gs);
			}
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1); 
	for(long long i=1;i<=n;i++)
	{
		cba(1/*xiabiao*/,0/*he*/,i/*geshu*/);
	}
	cout<<x%998244353;
	return 0;
}
