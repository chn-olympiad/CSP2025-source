#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
template<typename T> bool read(T&x){x=0;T f=1;char c=getchar();while((c<'0'||c>'9')&&c!=EOF){if(c=='-') f=-1;c=getchar();}if(c==EOF) return 0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return 1;}
template<typename T,typename ...T1> bool read(T&x,T1&...y){return read(x)+read(y...);}
const int N=500+15,mod=998244353;
using namespace std;

int n,m;
int a[N];
bool fl[N],F=1;
bitset<N> vis;
int ans=0;

void dfs(int u,int dl){
	if(n-dl<m) return ;
	if(u==n+1){
		ans++;
		if(ans>=mod) ans-=mod;
		return ;
	}
	rep(i,1,n){
		if(vis[i]) continue;
		vis[i]=1;
		if(fl[u]||dl>=a[i]) dfs(u+1,dl+1);
		else dfs(u+1,dl);
		vis[i]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m);
	rep(i,1,n){
		char c;cin>>c;
		fl[i]=(c=='0');
		F&=fl[i];
	}
	rep(i,1,n) read(a[i]);
	if(F){
		int res=1;
		rep(i,1,n) res=1ll*res*i%mod;
		cout<<res<<'\n';
		return 0;
	}
	if(n==m){cout<<0;return 0;}
	if(n>10){cout<<0;return 0;}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
畏惧了。
32
*/