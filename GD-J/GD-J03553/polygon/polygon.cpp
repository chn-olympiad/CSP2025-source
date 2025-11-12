#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
long long a[10010],minn=10000,maxx;
long long ans=0;
int n;
void bfs(int id,int k,int z,int num)
{
	if(n-id-1<k-z)
	{
		return ;
	}
	if(z==k)
	{
		for(int i=id+1;i<=n;i++)
		{
			if(a[i]>=num)
			{
				break;
			}
			ans++;
			ans=ans%=mod;
		}
		return ;
	}
	for(int i=id+1;i<=n;i++)
	{
		bfs(i,k,z+1,num+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	if(maxx<minn*2)
	{
		long long t=n*n,v=2;
		t%=mod;
		for(int i=3;i<=n;i++)
		{
			v*=i;
			v%=mod;
			t*=n;
			t%=mod;
			t/=i;
			ans+=t;
		}
		ans%=mod;
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int j=3;j<=n;j++)
	{
		bfs(0,j,1,0);
	}
	ans%=mod;
	printf("%lld",ans);
	return 0;
}

