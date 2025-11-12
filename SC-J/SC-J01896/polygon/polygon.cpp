#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5010,Mod=998244353;
ll n,arr[N],g[N][N],f[N],qpow[N];
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n=read();
	for(ll i=1;i<=n;i++) arr[i]=read();
	sort(arr+1,arr+n+1);
	g[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=5000;j++){
			g[i][j]=g[i-1][j];
			if(j-arr[i]>=0) g[i][j]+=g[i-1][j-arr[i]];
			g[i][j]%=Mod;
		}
	}
	qpow[0]=1;
	for(ll i=1;i<=n;i++) qpow[i]=qpow[i-1]*2%Mod;
	for(ll i=1;i<=n;i++){
		f[i]=qpow[i-1];
		for(ll j=0;j<=arr[i];j++){
			f[i]-=g[i-1][j];
			f[i]%=Mod;
		}
		f[i]+=Mod;
		f[i]%=Mod;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=f[i];
		ans%=Mod;
	}
	ans%=Mod;
	cout<<ans;
	return 0;
}