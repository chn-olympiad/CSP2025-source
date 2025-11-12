#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long read()
{
	char b=getchar();
	long long a=0;
	for(;'0'<=b&&b<='9';)
	{
		a=a*10+b-'0';
		b=getchar();
	}
	return a;
}
long long n,a[5100],ans;
bool b[5100];
void dfs(long long x,long long y,long long z,long long m)
{
	if(x==0)
	{
		if(z>m*2)
			ans=(ans+1)%Mod;
		return;
	}
	if(y==n)
		return;
	for(long long i=y+1;i<=n;i++)
	{
		dfs(x-1,i,z+a[i],max(m,a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(long long i=3;i<=n;i++)
		dfs(i,0,0,0);
	cout<<ans;
}