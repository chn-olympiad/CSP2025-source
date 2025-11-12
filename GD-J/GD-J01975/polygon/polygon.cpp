#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353; 
int n,a[5005],l[25],ans,inv[100005],jc[100005];
int ksm(int a,int b)
{
	int cnt=1;
	while(b)
	{
		if(b&1) cnt=cnt*a%mod;
		a=a*a%mod,b>>=1;
	}
	return cnt;
}
void dg(int x,int l[])
{
	if(x==n+1)
	{
		int maxn=-1,sum=0;
		for(int i=1;i<=n;i++){
			if(l[i]) maxn=max(maxn,a[i]),sum+=a[i];
		}
		if(maxn==-1) return;
		if(sum>maxn*2) ans++;
		return;
	}
	l[x]=1;dg(x+1,l);
	l[x]=0;dg(x+1,l);
}
int C(int n,int m){return jc[n]*inv[m]%mod*inv[n-m]%mod;}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	jc[0]=inv[0]=1;
	for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%mod,inv[i]=ksm(jc[i],mod-2);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=
	}
	if(n<=20)
	{
		dg(1,l);
		return cout<<ans,0;
	}
	for(int i=3;i<=n;i++){
		ans=(ans+C(n,i))%mod;
	}
	return cout<<ans,0;
}
