#include<bits/stdc++.h>
#define ll long long
#define R register
#define PII pair<int,int>
#define mk(x,y) make_pair(x,y)
#define lowbit(x) (x&-x)
using namespace std;
const int N=1e6+5;
bool st;
struct edge{int u,v;ll w;}e[N],e2[N],b[11][10005];
vector<edge> f[(1<<10)];
int n,m,k,fa[N],siz[N],cnt;ll val[11],id[N];ll res=0;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline ll solve(int state){
	for(R int i=1;i<=n+k;++i)fa[i]=i,siz[i]=1;
	int to=id[lowbit(state)];
	int num=n;ll sum=0;
	for(R int i=0;i<k;++i)if((state&(1<<i))){
		sum+=val[i];++num;
	}
	int idpre=(state^(lowbit(state)));
	int le=f[idpre].size();
	int cur=0;
	int cur1=-1,cur2=0;
	while(cur1<le-1&&cur2<n){
		if(f[idpre][cur1+1].w<b[to][cur2+1].w){
			e2[++cur]=f[idpre][cur1+1];++cur1;
		}else{
			e2[++cur]=b[to][cur2+1];++cur2;
		}
	}
	while(cur1<le-1){e2[++cur]=f[idpre][cur1+1];++cur1;}
	while(cur2<n){e2[++cur]=b[to][cur2+1];++cur2;}
	cnt=0;
	for(R int i=1;i<=cur;++i){
		if(cnt==num-1)break;
		int u=find(e2[i].u),v=find(e2[i].v);
		if(u!=v){
			++cnt;
			if(siz[u]>siz[v])swap(u,v);
			fa[u]=v;
			siz[v]+=siz[u];
			++cur;sum+=e2[i].w;
			f[state].emplace_back(e2[i]);
		}
	}
	return sum;
}
bool ed;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(n==1){
		cout<<0;return 0;
	}
	for(R int i=1;i<=n;++i)fa[i]=i;
	for(R int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,[](edge x,edge y){return x.w<y.w;});
	for(R int i=1;i<=m;++i){
		if(cnt==n-1)break;
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			++cnt;
			fa[u]=v;
			f[0].emplace_back(e[i]);
			res+=e[i].w;
		}
	}
	for(R int i=0;i<k;++i)id[(1<<i)]=i;
	for(R int i=0;i<k;++i){
		cin>>val[i];
		for(R int j=1;j<=n;++j){cin>>b[i][j].w;b[i][j].u=n+i+1,b[i][j].v=j;}
		sort(b[i]+1,b[i]+n+1,[](edge x,edge y){return x.w<y.w;});
	}
	int all=(1<<k)-1;
	for(R int i=1;i<=all;++i){
		res=min(res,solve(i));
	}
	cout<<res;
	return 0;
}