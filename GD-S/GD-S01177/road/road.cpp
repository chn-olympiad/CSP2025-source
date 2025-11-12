// #define DEBG 1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> PII;
const int maxn=1e4+10,maxm=1e6+35,maxk=16;
const ll inf=1e18;

ll ans;
namespace IO{
    #define MAXBUFFSIZE (1<<20)
    char buff[MAXBUFFSIZE],*head=buff,*tail=buff;
    inline char gc(){
        #ifdef DEBG
            return getchar();
        #endif
        if(head==tail) head=buff,tail=head+fread(buff,1,MAXBUFFSIZE,stdin);
        return (head==tail)?(EOF):*(head++);
    }
    inline ll read(){
        ll res=0,tf=1;
        char c=gc();
        while(c<'0'||c>'9') tf*=(c=='-')?(-1):(1),c=gc();
        while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=gc();
        return res*tf;
    }
}
using namespace IO;

int n,m,k;
struct Edge{
	int u,v;
	ll w;
	Edge(){}
	Edge(int u,int v,ll w):u(u),v(v),w(w){}
}e[maxm];

ll c[maxk];
PII ap[maxk][maxn];
ll _bind[maxk];
void input(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		ll w=read();
		e[i]=Edge(u,v,w);
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		ll mn=inf;
		for(int j=1;j<=n;++j){
			ap[i][j]={j,read()};
			if(ap[i][j].first<mn){
				mn=ap[i][j].first;
				_bind[i]=j;
			}
		}
		sort(ap[i]+1,ap[i]+n+1,[](PII x,PII y){return x.second<y.second;});
	}
}

int bcj[maxn],hi[maxn];
int root(int x){
	if(bcj[x]==x) return x;
	return bcj[x]=root(bcj[x]);
}
void mergebcj(int a,int b){
	int ra=root(a),rb=root(b);
	if(hi[ra]<hi[rb]) bcj[ra]=rb;
	else if(hi[ra]>hi[rb]) bcj[rb]=ra;
	else{
		bcj[ra]=rb;
		hi[rb]++;
	}
}
void bcjinit(){
	for(int i=1;i<=n+n-1;++i){
		bcj[i]=i;
		hi[i]=1;
	}
}

bool flag[maxm];
void calc_tree(){
	sort(e+1,e+m+1,[](Edge x,Edge y){return x.w<y.w;});
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v;ll w=e[i].w;
		if(root(u)!=root(v)){
			mergebcj(u,v);
			flag[i]=1;
			ans+=w;
		}
	}
}


vector<PII> edge[maxn];
int fa[maxn];
vector<int> sons[maxn];
int siz[maxn],mainson[maxn];
ll faw[maxn];
int dep2[maxn];
void dfs(int x,int father){
	siz[x]=1;
	int mx=-1;
	for(auto p: edge[x]){
		int y=p.first;
		ll w=p.second;
		if(y!=father){
			fa[y]=x;
			dep2[y]=dep2[x]+1;
			// cout<<y<<" "<<x<<endl;
			sons[x].emplace_back(y);
			faw[y]=w;
			dfs(y,x);
			siz[x]+=siz[y];
			if(siz[y]>mx){
				mx=siz[y];
				mainson[x]=y;
			}
		}
	}
}

int idx;
int id[maxn];
int lineheadf[maxn],linehead[maxn];
int dep[maxn];
int faf[maxn];
ll a[maxn];
void dfs2(int x){
	++idx;
	id[x]=idx;
	// cout<<x<<" "<<idx<<endl;
	a[id[x]]=faw[x];
	dep[id[x]]=dep2[x];
	linehead[id[x]]=id[lineheadf[x]];
	faf[id[x]]=id[fa[x]];
	for(auto y: sons[x]){
		if(y==mainson[x]) lineheadf[y]=lineheadf[x],dfs2(y);
	}
	for(auto y: sons[x]){
		if(y!=mainson[x]){
			lineheadf[y]=y;
			dfs2(y);
		}
	}
}
void build_tree(){
	for(int i=1;i<=m;++i){
		if(flag[i]){
			edge[e[i].u].push_back({e[i].v,e[i].w});
			edge[e[i].v].push_back({e[i].u,e[i].w});
		}
	}
	dep2[1]=1;
	dfs(1,0);
	lineheadf[1]=1;
	dfs2(1);
}

typedef pair<ll,int> PLI;
struct Segtree{
	#define lson o<<1
	#define rson o<<1|1
	#define nmid int mid=(nowl+nowr)>>1

	//区间查询max，单点修改
	PLI t[maxn<<2];
	void push_up(int o){
		t[o]=max(t[lson],t[rson]);
	}
	void build(int nowl,int nowr,int o){
		if(nowl==nowr){
			t[o]={a[nowl],nowl};
			return;
		}
		nmid;
		build(nowl,mid,lson);
		build(mid+1,nowr,rson);
		push_up(o);
	}
	PLI query(int nowl,int nowr,int l,int r,int o){
		if(l>r) return {-inf,0};
		if(l<=nowl&&nowr<=r){
			return t[o];
		}
		nmid;
		PLI res={-inf,0};
		if(l<=mid) res=max(res,query(nowl,mid,l,r,lson));
		if(r>mid) res=max(res,query(mid+1,nowr,l,r,rson));
		return res;
	}
	void update(int nowl,int nowr,int p,int o,ll val){
		if(nowl==nowr){
			t[o]={val,nowl};
			return;
		}
		nmid;
		if(p<=mid) update(nowl,mid,p,lson,val);
		else update(mid+1,nowr,p,rson,val);
		push_up(o);
	}
}sgt;


PLI query(int x,int y){
	PLI res={-inf,0};
	x=id[x],y=id[y];
	while(linehead[x]!=linehead[y]){
		if(dep[linehead[x]]>dep[linehead[y]]){
			res=max(res,sgt.query(1,n,linehead[x],x,1));
			x=faf[linehead[x]];
		}
		else{
			res=max(res,sgt.query(1,n,linehead[y],y,1));
			y=faf[linehead[y]];
		}
	}
	if(dep[x]<dep[y]) swap(x,y);
	res=max(res,sgt.query(1,n,y+1,x,1));
	return res;
}

ll anss;
Edge e2[maxn*maxk];
int cnt;
void solve(){
	for(int S=0;S<(1<<k);++S){
		ll tot=0;
		sgt.build(1,n,1);
		for(int j=1;j<=k;++j){
			if(S&(1<<(j-1))){
				// cout<<"j="<<j<<"\n";
				tot+=c[j]+ap[j][_bind[j]].second;
				// cout<<"tot="<<tot<<endl;
				for(int k=1;k<=n;++k){
					if(ap[j][k].first==_bind[j]) continue;
					e2[++cnt]=Edge(_bind[j],ap[j][k].first,ap[j][k].second);
				}
			}
		}
		sort(e2+1,e2+cnt+1,[](Edge x,Edge y){return x.w<y.w;});
		for(int it=1;it<=cnt;++it){
			int u=e2[it].u,v=e2[it].v;
			ll w=e2[it].w;
			// cout<<"req:"<<u<<" "<<v<<endl;
			PLI res=query(u,v);
			// cout<<"res="<<res.first<<" "<<res.second<<endl;
			if(res.first!=-inf&&w<res.first){
				tot+=w-res.first;
				sgt.update(1,n,res.second,1,-inf);
			}
		}

		anss=min(anss,ans+tot);
		// cout<<endl;
		cnt=0;
	}
}

int main(){
	#ifndef DEBG
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif

	input();
	bcjinit();
	calc_tree();
	build_tree();
	anss=ans;
	solve();
	printf("%lld\n",anss);
    return 0;
}
