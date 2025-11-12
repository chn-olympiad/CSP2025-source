#include<bits/stdc++.h>
const long long N=998244353;
using namespace std;
long long n,a[5005],b[100005],c[5005],ans;
void f(long long x)
{
	long long mx=0,sum=0;
	for(int i=1;i<=x;i++)
	{
		sum+=a[b[i]];
		mx=max(mx,a[b[i]]);
	}
	if(sum>2*mx) ans=(ans+1)%N;
}
void f2(long long x)
{
	long long mx=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=i;
	}
	for(int i=1;i<=x;i++)
	{
		sum+=a[b[i]];
		mx=max(mx,a[b[i]]);
	}
	if(sum>2*mx) ans++;
}
void dfs(long long x,long long y)
{
	if(x==y)
	{
		f(y);
	}
	for(int i=b[x]+1;i<=n;i++)
	{
		if(c[i]==0)
		{
			c[i]=1;
			b[x+1]=i;
			dfs(x+1,y);
			c[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	for(int i=3;i<n;i++)
	{
		dfs(0,i);
	}
	f2(n);
	cout<<ans%N;
	return 0;
}
