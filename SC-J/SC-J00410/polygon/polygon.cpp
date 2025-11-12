#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int Mod=998244353;
int a[N];
int fac[N],inv[N];
int qpow(int x,int y)
{
	int z=1,d=x;
	for(;y;y>>=1)
	{
		if(y&1)
		{
			z*=d;
			if(z>=Mod) z%=Mod;
		}
		d*=d;
		if(d>=Mod) d%=Mod;
	}
	return z;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++) cin>>a[i],maxa=max(maxa,a[i]);
	sort(a+1,a+n+1);
	if(maxa==1)
	{
		int ans=0;
		fac[0]=1;
		inv[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=fac[i-1]*i;
			fac[i]%=Mod;
			inv[i]=qpow(fac[i],Mod-2);
		}
		for(int b=3;b<=n;b++)
		{
			int nowans=fac[n]*inv[b];
			if(nowans>Mod) nowans%=Mod;
			nowans*=inv[n-b];
			if(nowans>Mod) nowans%=Mod;
			ans+=nowans;
			if(ans>Mod) ans-=Mod;
			if(ans==0) 
			{
				cout<<nowans<<'\n';
			}
		}
		cout<<ans;
	}
	else if(n<=3)
	{
		if(n<3) cout<<0;
		else
		{
			if(a[1]+a[2]+a[3]<=2*maxa) cout<<0;
			else cout<<1;
		}
	}
	else
	{
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0,sum=0;
			int maxj;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j)) cnt++,sum+=a[j+1],maxj=j;
			}
			if(cnt<3) continue;
			else if(sum<=2*a[maxj+1]) continue;
			ans++;
		}
		cout<<ans;
	}
	return 0;
}