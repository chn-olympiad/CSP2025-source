#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,y=0,b[505],t=0,c[505],d[505];
bool v[505];
string a;
bool h=1;
void dfs(int x)
{
	if(x==n+1)
	{
		long long h=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i-1]<b[c[n]]&&a[c[n]-1]=='1')
			{
				h++;
			}
			else
			{
				d[i]++;
			}
			d[i]+=d[i-1];
		}
		if(h>=m)
		{
			y++;
			y=y%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			c[x]=i;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')
		{
			h=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		if(b[i]!=0)y++;
	}
	if(h==1)
	{
		long long t=1;
		for(long long i=1;i<=y;i++)
		{
			t=t*i%mod;
		}
		printf("%lld",t%mod);
		return 0;
	}
	y=0;
	dfs(1);
	printf("%d",y);
	
	return 0;
}
