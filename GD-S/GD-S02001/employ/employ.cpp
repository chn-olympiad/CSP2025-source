#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[505],c[505];
int b[505],jc[505],p[505],ans;
int ksm(int a,int b)
{
	int re=1;
	while(b)
	{
		if(b&1)re=re*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return re;
}
bool vis[10005];
void dfs(int x)
{
	if(x>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=c[p[i]]){
				sum++;
				continue;
			}
			sum+=a[i];
			if(sum>m)return;
//			cout<<p[i]<<" ";
		}
//		cout<<endl;
		if(n-sum==m)
		{
			ans++;
//			cout<<sum<<endl;
//			for(int i=1;i<=n;i++)cout<<p[i]<<" ";
//			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int s=0;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i]=ch-'0';
		a[i]=!a[i];
		s+=a[i];
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
