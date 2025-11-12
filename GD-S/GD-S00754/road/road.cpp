#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define ll long long
#define db long double
#define endl '\n'
using namespace std;
const int MAXN=2e5+20,MAXM=6e6+5,MOD=0;
const long long INF=(1ll<<62);
ll T=1,n,m,K,M;
struct EDGE{
	ll u,v,w,id;
	bool operator < (const EDGE &tmp) const{
		return w<tmp.w;
	}
} e[MAXM];
ll fa[MAXN],a[MAXN],g[11][MAXN];
ll sz[MAXN]; 
void init(){
	for (int i=1;i<=n;i++) fa[i]=i;
}
void Init(){
	for (int i=1;i<=n+K;i++) fa[i]=i;
	for (int i=1;i<=n;i++) sz[i]=1;
	for (int i=n+1;i<=n+K;i++) sz[i]=0; 
}
ll getfa(ll x){
	if (x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
ll kruskal(){
	ll cnt=0,res=0;
	init();
	sort(e+1,e+1+M);
	for (int i=1;i<=M;i++){
		ll f1=getfa(e[i].u),f2=getfa(e[i].v);
		if (f1==f2) continue;
		fa[f2]=f1,++cnt,res+=e[i].w; 
		if (cnt==n-1) break;
	}
	return res;
}
ll Cnt[12],Val[12];
ll Kruskal(ll st){
	ll cnt=0,res=0;
	Init();
	for (int i=1;i<=K;i++) Cnt[i]=Val[i]=0; 
	for (int i=1;i<=M;i++){
		if (e[i].id!=0 && !((1ll<<(e[i].id-1))&st)) continue; 
		ll f1=getfa(e[i].u),f2=getfa(e[i].v);
		if (f1==f2) continue;
		fa[f2]=f1,sz[f1]+=sz[f2];
		res+=e[i].w; 
		if (e[i].u>n) ++Cnt[e[i].u-n],Val[e[i].u-n]+=e[i].w;
		if (sz[f1]==n) break;
	}
	for (int i=1;i<=K;i++) if (Cnt[i]==1) res-=Val[i];
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (T--){
		cin>>n>>m>>K;
		for (int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
			e[i].id=0;
		}
		bool flag=0;
		for (int i=1;i<=K;i++){
			cin>>a[i];
			if (a[i]) flag=1;
			bool chk=0;
			for (int j=1;j<=n;j++){
				cin>>g[i][j];
				if (!g[i][j]) chk=1;
			}
			if (!chk) flag=1;
		}
		if (flag){
			ll ans=INF;
			M=m;
			for (int i=1;i<=K;i++){
				for (int j=1;j<=n;j++) e[++M]={i+n,j,g[i][j],i};
			}
			sort(e+1,e+1+M);
			for (int st=0;st<(1ll<<K);st++){
				ll tmp=0;
				for (int i=1;i<=K;i++) if ((1ll<<(i-1))&st) tmp+=a[i];
				ans=min(ans,Kruskal(st)+tmp);
			}
			cout<<ans<<endl; 
		}
		else{
			M=m;
			for (int i=1;i<=K;i++){
				for (int j=1;j<=n;j++){
					if (g[i][j]) continue;
					for (int k=1;k<=n;k++){
						if (k==j) continue;
						e[++M]={j,k,g[i][k]};
					}
					break;
				}
			}
			cout<<kruskal()<<endl;
		}
	}
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
