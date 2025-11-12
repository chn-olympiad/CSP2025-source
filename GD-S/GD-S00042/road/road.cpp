#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5,MAXM=1e6+5,INF=0x3f3f3f3f;
int n,m,k,fa[MAXN];
struct node{
	int u,v,w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
priority_queue<node> q;
inline int fd(int u){
	if(u==fa[u])return u;
	return fa[u]=fd(fa[u]);
}
int a[15][MAXN],id[MAXN];
int head[MAXN],cnt=1;
struct edge{
	int next,to,dis;
}e[MAXN*2];
inline void addedge(int u,int v,int w){
	e[++cnt]=(edge){head[u],v,w};
	head[u]=cnt;
}
int dfn[MAXN],tot,dep[MAXN],son[MAXN],fat[MAXN],siz[MAXN],to[MAXN],top[MAXN],wei[MAXN];
inline void dfs1(int u,int f){
	fat[u]=f;
	siz[u]=1;
	dep[u]=dep[f]+1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to,w=e[i].dis;
		if(v==f)continue;
		dfs1(v,u);
		wei[v]=w;
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void dfs2(int u,int t){
	top[u]=t;
	dfn[u]=++tot;
	to[tot]=u;
	if(son[u])dfs2(son[u],t);
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fat[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
struct tree{
	int l,r,maxn,id;
	bool vis;
}t[MAXN*4];
inline void push_up(tree &t,tree lz,tree rz){
	if(lz.maxn>rz.maxn){
		t.maxn=lz.maxn,t.id=lz.id;
	}else{
		t.maxn=rz.maxn,t.id=rz.id;
	}
}
inline void build(int i,int l,int r){
	t[i].l=l,t[i].r=r;
	if(l==r){
		t[i].maxn=wei[to[l]];
		t[i].id=l;
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(t[i],t[i*2],t[i*2+1]);
}
inline void modify(int i,int s){
	if(t[i].l>s||t[i].r<s)return;
	if(t[i].l==s&&t[i].r==s){
		t[i].vis=1;
		t[i].maxn=-INF;
		t[i].id=-1;
		return;
	}
	modify(i*2,s),modify(i*2+1,s);
	push_up(t[i],t[i*2],t[i*2+1]);
}
inline tree query(int i,int l,int r){
	if(t[i].l>=l&&t[i].r<=r)return t[i];
	if(t[i*2].r<l)return query(i*2+1,l,r);
	if(t[i*2+1].l>r)return query(i*2,l,r);
	tree ans,lz=query(i*2,l,r),rz=query(i*2+1,l,r);
	push_up(ans,lz,rz);
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		q.push((node){u,v,w});
	}
	for(int i=1;i<=k;i++){
		ll minn=INF;
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
			if(j&&a[i][j]<minn){
				minn=a[i][j];
				id[i]=j;
			}
		}
	}
	ll ans=0;
	for(int cnt=1;!q.empty()&&cnt<n;){
		int u=q.top().u,v=q.top().v,w=q.top().w;q.pop();
		int _u=fd(u),_v=fd(v);
		if(_u==_v)continue;
		cnt++,ans+=w,fa[_u]=_v;
		addedge(u,v,w),addedge(v,u,w);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	ll tmp=0;
	for(int i=1;i<=k;i++){
		ll sum=a[i][0]+a[i][id[i]];
		bool c=0;
		for(int j=1;j<=n;j++){
			if(j==id[i])continue;
			int u=id[i],v=j,w=a[i][j]+(c?0:sum);
			int maxn=-INF,sp=0;
			while(top[u]!=top[v]){
				if(dep[top[u]]<dep[top[v]])swap(u,v);
				tree tmp=query(1,dfn[top[u]],dfn[u]);
				if(tmp.maxn>maxn){
					maxn=tmp.maxn;
					sp=tmp.id;
				}
				u=fat[top[u]];
			}
			if(u!=v){
				if(dep[u]>dep[v])swap(u,v);
				tree tmp=query(1,dfn[u]+1,dfn[v]);
				if(tmp.maxn>maxn){
					maxn=tmp.maxn;
					sp=tmp.id;
				}
			}
			if(w<maxn){
				tmp+=maxn-w;
				modify(1,sp);
				c=1;
			}
		}
	}
	cout<<ans-tmp;
}
