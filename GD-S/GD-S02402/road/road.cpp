#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+25,K=12,inf=1e9+15;
inline ll read(){
	ll x=0;char f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0',c=getchar();}
	return f?x:-x;
}
int n,m,k,c[K],a[K][N];
ll ans;
struct edge{
	int v,w;
	friend bool operator <(edge p,edge q){
		return p.w<q.w;
	}
};
vector<edge>g[N];
inline void add(int u,int v,int w){
	g[u].emplace_back(edge{v,w});
}
bitset<N>vis,vis1;
struct tnode{int l,r,x,p;};
struct segment_tree{
	tnode t[N*4];
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((t[u].l+t[u].r)>>1)
	inline void push_up(int u){
		if(t[ls].x<=t[rs].x)t[u].x=t[ls].x,t[u].p=t[ls].p;
		else t[u].x=t[rs].x,t[u].p=t[rs].p;
	}
	void build(int u,int l,int r){
		t[u]={l,r,inf,l};
		if(l!=r)build(ls,l,mid),build(rs,mid+1,r);
	}
	void update(int u,int k,int val){
		if(t[u].l==t[u].r){
			t[u].x=val;
			return;
		}
		if(k<=mid)update(ls,k,val);
		else update(rs,k,val);
		push_up(u);
	}
	#undef ls
	#undef rs
	#undef mid
};
segment_tree t1;
int dis[N];
inline ll prim(int bk){
	ll res=0;
	t1.build(1,1,n+k);
	for(int i=1;i<=n+k;++i)dis[i]=inf,vis1[i]=0;
	t1.update(1,1,0),dis[1]=0;
	for(int i=1;i<=bk;++i){
		int u=t1.t[1].p;
		res+=t1.t[1].x,vis1[u]=1;
		dis[u]=inf,t1.update(1,u,inf);
		for(edge j:g[u]){
			if(!vis[j.v]||vis1[j.v])continue;
			if(j.w<dis[j.v]){
				dis[j.v]=j.w;
				t1.update(1,j.v,j.w);
			}
		}
	}
	return res;
}
bool A=1;
vector<edge>g1[N];
struct ufs{
	int s[N];
	inline void init(){for(int i=1;i<=n+k;++i)s[i]=i;}
	int find(int u){return u!=s[u]?s[u]=find(s[u]):u;}
	inline void unify(int u,int v){s[find(v)]=find(u);}
};
ufs u1;
inline void add1(int u,int v,int w){
	g1[u].emplace_back(edge{v,w});
}
inline ll prim1(int bk){
	ll res=0;
	t1.build(1,1,n+k);
	for(int i=1;i<=n+k;++i)dis[i]=inf,vis1[i]=0;
	t1.update(1,1,0),dis[1]=0;
	for(int i=1;i<=bk;++i){
		int u=t1.t[1].p;
		res+=t1.t[1].x,vis1[u]=1;
		dis[u]=inf,t1.update(1,u,inf);
		for(edge j:g1[u]){
			if(!vis[j.v]||vis1[j.v])continue;
			if(j.w<dis[j.v]){
				dis[j.v]=j.w;
				t1.update(1,j.v,j.w);
			}
		}
	}
	return res;
}
inline void workA(){
	u1.init();
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]==0){
				u1.unify(i+n,j);
			}
		}
	}
	int cnt1=0;
	for(int u=1;u<=n+k;++u){
		if(u==u1.find(u))++cnt1,vis[u]=1;
		int x=u1.find(u);
		for(edge j:g[u]){
			int y=u1.find(j.v);
			if(x!=y){
				add1(x,y,j.w),add1(y,x,j.w);
			}
		}
	}
	printf("%lld",prim1(cnt1));
}
int solve(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		A&=(c[i]==0);
		bool flg0=0;
		for(int j=1;j<=n;++j){
			a[i][j]=read();
			add(i+n,j,a[i][j]),add(j,i+n,a[i][j]);
			if(a[i][j]==0)flg0=1;
		}
		A&=(flg0);
	}
	for(int i=1;i<=n+k;++i){
		sort(g[i].begin(),g[i].end());
	}
	ans=inf;
	if(k<=5){
		for(int i=1;i<=n;++i){
			vis[i]=1;
		}
		for(int mx=(1<<k),i=0;i<mx;++i){
			int cnt=0;
			ll sum=0;
			for(int j=1;j<=k;++j){
				if((i>>(j-1))&1)vis[n+j]=1,++cnt,sum+=c[j];
			}
			ll w=prim(n+cnt);
			ans=min(ans,sum+w);
			for(int j=1;j<=k;++j){
				vis[n+j]=0;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(A){
		workA();
		return 0;
	}
	for(int i=1;i<=n;++i){
		vis[i]=1;
	}
	for(int mx=(1<<k),i=0;i<mx;++i){
		int cnt=0;
		ll sum=0;
		for(int j=1;j<=k;++j){
			if((i>>(j-1))&1)vis[n+j]=1,++cnt,sum+=c[j];
		}
		ll w=prim(n+cnt);
		ans=min(ans,sum+w);
		for(int j=1;j<=k;++j){
			vis[n+j]=0;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	while(T--){
		solve();
		if(T!=0)printf("\n");
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
