#include <bits/stdc++.h>
#define name "road"
#define popcnt __builtin_popcount
using namespace std;
const int N=10007,M=1000007,K=11;
typedef long long li;
const li inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	int u,v;
	li w;
	bool operator<(const edge o)const{return w<o.w;}
	bool operator>(const edge o)const{return w>o.w;}
} e[M],a[K][N];
typedef priority_queue<edge,vector<edge>,greater<edge>> pq;
struct dsu{
	int _p[N+K],*p=_p+K,_sz[N+K],*sz=_sz+K;
	void init(int n,int k){for(int i=-k;i<=n;i++)p[i]=i,sz[i]=1;}
	int find(int x){return (x==p[x])?x:(p[x]=find(p[x]));}
	bool merge(int u,int v){
		int x=find(u),y=find(v);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		sz[y]+=sz[x],p[x]=y;
		return 1;
	}
} dsu;
pq q;
li c[K];
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].w,a[i][j].u=-i,a[i][j].v=j;
	}
	sort(e+1,e+m+1);
	dsu.init(n,0);
	int cnt=0;
	li ans=0;
	for(int i=1;i<=m;i++) if(dsu.merge(e[i].u,e[i].v)) a[0][++cnt]=e[i],ans+=e[i].w;
	for(int i=1;i<=k;i++) sort(a[i]+1,a[i]+n+1);
	for(int i=1;i<(1<<k);i++){
		dsu.init(n,k);
		pq().swap(q);
		q.push({0,1,a[0][1].w});
		for(int j=i;j;j-=(j&-j)) q.push({__lg(j&-j)+1,1,a[__lg(j&-j)+1][1].w});
		cnt=0;
		int qwq=n+popcnt(i)-1;
		li res=0;
		for(int j=i;j;j-=(j&-j)) res+=c[__lg(j&-j)+1];
		while(cnt<qwq){
			auto u=q.top();
			q.pop();
			if(dsu.merge(a[u.u][u.v].u,a[u.u][u.v].v)) res+=u.w,cnt++;
			if(u.v<n-(!u.u)) q.push({u.u,u.v+1,a[u.u][u.v+1].w});
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}

//froepen("roads1.in","r",stdin);
//ferepen("road.out","r",stdout)
//rp++
//CSP AK me
