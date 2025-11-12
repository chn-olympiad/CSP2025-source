#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5005,mod=998244353;
ll n,ans;
ll a[N],t[N],c[N];

ll mul(int x,int y)
{
	ll ans=1;
	for(int i=x;i<=y;i++)
		ans=ans*i%mod;
	return ans;
}
void pianfen()
{
	c[0]=c[n]=1;
	for(int i=1;i<=n/2;i++)
		c[i]=c[n-i]=(mul(n-i+1,n)/mul(1,i))%mod;
	for(int i=3;i<=n;i++)
		ans=(ans+c[i])%mod;
	cout<<ans;
	exit(0);
}
void dfs(int num,int m)
{
	if(num==m+1)
	{
		int sum=0;
		for(int i=1;i<m;i++)
			sum+=a[t[i]];
		if(sum>a[t[m]]) ans++;
		return;
	}
	for(int i=t[num-1]+1;i<=n;i++)
	{
		t[num]=i;
		dfs(num+1,m);
		t[num]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	bool same=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) same=0;
	}
	if(same) pianfen();
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		memset(t,0,sizeof t);
		dfs(1,i);
	}
	cout<<ans%mod;
	return 0;
}
