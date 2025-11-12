#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
int n;
ll ans;
const int N=5e3+10;
const ll Mod=998244353;
int a[N];
void dfs(int x,int cnt,int sum,int l)
{
	if(x>n)
	{
		if(sum>2*l) ans++;
		if(ans>=Mod) ans-=Mod;
	}
	else
	{
		dfs(x+1,cnt+1,sum+a[x],max(l,a[x]));
		dfs(x+1,cnt,sum,l);
	}
	return;
}
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%Mod;
		a=a*a%Mod;
		b>>=1; 
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int mx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	if(mx==1)
	{
		for(int i=3;i<=n;i++)
		{
			ll res1=1,res2=1;
			for(int j=1;j<=i;j++)
				res1=res1*j%Mod,res2=res2*(n-j+1)%Mod;
			ans=(ans+res2*qpow(res1,Mod-2)%Mod)%Mod;
		}
	}
	else dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
