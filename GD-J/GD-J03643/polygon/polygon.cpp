#include<bits/stdc++.h>
using namespace std;
const int MOD1=998,MOD2=244,MOD3=353,N=5010;
long long n,a[N],sum=0,lssum=0,vis[N],lsnum[N],themax[N];
inline void dfs(int place,int last)
{
	if(place>=4)
	{
		if(lssum>2*themax[place-1])
		{
			sum++;
			sum%=MOD1;
			sum%=MOD2;
			sum%=MOD3;
		}
	}
	for(register int i=last+1;i<=n;i++)
	{
		if(vis[i])
		{
			continue;
		}
		else
		{
			lsnum[place]=i;
			vis[i]=1;
			lssum+=a[i];
			themax[place]=max(themax[place-1],a[i]);
			dfs(place+1,i);
			lssum-=a[i];
			vis[i]=0;
			themax[place]=0;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(1,0);
	printf("%lld",sum);
	return 0;
}
