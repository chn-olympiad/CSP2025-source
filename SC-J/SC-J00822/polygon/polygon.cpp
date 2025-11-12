#include <bits/stdc++.h>
using namespace std;
//998244353
int a[19010];
int	c[10010];
finnn(int l,int r)
{
	int i=1,ans=1,g=1;
	for(i=l;i>=l-r+1;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	for(i=1;i<=r;i++)
	{
		g*=i;
		g%=998244353;
	}
	return ans/g;
}
fffff(int l)
{
	int ans=0;
	for(int i=l;i>=1;i++)
	{
		ans+=finnn(l,i);
		ans%=998244353;
	}
	return ans;
}
int main()
{
	
	freopen(" polygon.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i=0,ans =0,n=0;
	cin>>n;
	int b=0; 
	for(i=0;i<n;i++)
	{
		cin>>b;
		a[b]++;
		
	}
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		ans+=fffff(i);
		ans%=998244353;
	}
	cout<<ans;
	
	return 0;
}