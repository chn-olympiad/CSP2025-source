#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll n,k,arr[N],s[N],L[N],f[N];
vector<ll> g[N];
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
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n=read(),k=read();
	for(ll i=1;i<=n;i++){
		arr[i]=read();
		s[i]=s[i-1]^arr[i];
		g[s[i]].emplace_back(i);
	}
	for(ll i=0;i<N;i++) sort(g[i].begin(),g[i].end());
	for(ll i=1;i<=n;i++){
		ll now=s[i]^k;
		ll cur=lower_bound(g[now].begin(),g[now].end(),i)-g[now].begin()-1;
		if(cur!=-1)L[i]=g[now][cur];
		else L[i]=-1;
		if(now==0&&cur==-1) f[i]=1;
	}
	for(ll i=1;i<=n;i++){
		if(L[i]!=-1)f[i]=max({f[i-1],f[L[i]]+1,f[i]});
		else f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n];
	return 0;
}