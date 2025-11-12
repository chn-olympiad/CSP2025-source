#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int M=1e6+10;
const int K=25;
const ll inf=1e18;
struct edge{
	int u,v;
	ll w;
};
int n,m,k,nbs[N],tot,c[K],a[K][N],f[N];
ll ans;
vector<edge> g;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void LCM(){
	int cnt=0;
	sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<g.size() && cnt<n-1;i++){
		int u=g[i].u;
		int v=g[i].v;
		ll w=g[i].w;
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			ans+=w;
			cnt++;
		}
	}
}
inline bool check_(){
	for(int i=1;i<=k;i++)
		if(c[i]) return 0;
	return 1;
}
inline void solve1(){
	LCM();
	printf("%lld",ans);
}
inline void solve2(){
	for(int i=1;i<=k;i++){
		int p=0;
		for(int j=1;j<=n;j++)
			if(!a[i][j]){
				p=j;
				break;
			}
		for(int j=1;j<=n;j++)
			if(j!=p) g.push_back({p,j,a[i][j]});
	}
	LCM();
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,x,y,z;i<=m;i++) x=read(),y=read(),z=read(),g.push_back({x,y,z}),g.push_back({y,x,z});
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(!k) solve1();
	else solve2();
	return 0;
}
