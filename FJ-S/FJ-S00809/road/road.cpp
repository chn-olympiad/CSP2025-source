#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int M=1e6+10,V=1e5+10;
const int N=1e4+20;
const ll INF=1e11;
int n,m,k;
int fa[N];
int cost[15][N];
int c[15];
bool vis[15];
ll lst_ans=INF;

struct edge{
	int u,v,w;
}E[M+V],q[M];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

bool cmp(const edge &x,const edge &y){
	return x.w<y.w;
}

inline void get_sol(vector<int> a){
	ll res=0;
	rep(i,1,k)vis[i]=0;
	for(int i=0;i<(int)a.size();++i){
		int x=a[i];
		if(x==1){
			vis[i+1]=1;
			res+=c[i+1];
		}
	}
	int cnt=0;
	rep(i,1,m){
		int u=q[i].u,v=q[i].v,w=q[i].w;
		++cnt;
		E[cnt].u=u;
		E[cnt].v=v;
		E[cnt].w=w;
	}
	int idx=0;
	rep(i,1,k){
		if(!vis[i])continue;
		++idx;
		rep(j,1,n){
			++cnt;
			E[cnt].u=n+i;
			E[cnt].v=j;
			E[cnt].w=cost[i][j];
		}
	}
	sort(E+1,E+cnt+1,cmp);
	rep(i,1,n+k)fa[i]=i;
	for(int i=1;i<=cnt;++i){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		u=find(u),v=find(v);
		if(u==v)continue;
		fa[u]=v;
		res+=w;
	}
	lst_ans=min(lst_ans,res);
}

void dfs(int now,vector<int> pos){
	if(now==k+1){
		get_sol(pos);
		return ;
	}
	pos.push_back(0);
	dfs(now+1,pos);
	pos.pop_back();
	pos.push_back(1);
	dfs(now+1,pos);
	pos.pop_back();
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		int cnt=0;
		rep(i,1,m){
			int u,v,w;
			cin>>u>>v>>w;
			++cnt;
			E[cnt].u=u;
			E[cnt].v=v;
			E[cnt].w=w;
		}
		rep(i,1,n)fa[i]=i;
		sort(E+1,E+cnt+1,cmp);
		ll ans=0;
		for(int i=1;i<=cnt;++i){
			int u=E[i].u,v=E[i].v,w=E[i].w;
			u=find(u),v=find(v);
			if(u==v)continue;
			fa[u]=v;
			ans+=w;
		}
		cout<<ans<<'\n';
		return 0;
	}
	rep(i,1,m){
		cin>>q[i].u>>q[i].v>>q[i].w;
	}
	bool flag=1;
	rep(i,1,k){
		cin>>c[i];
		flag&=(c[i]==0);
		rep(j,1,n){
			cin>>cost[i][j];
		}
	}
	if(flag){
		int cnt=0;
		rep(i,1,m){
			int u=q[i].u,v=q[i].v,w=q[i].w;
			++cnt;
			E[cnt].u=u;
			E[cnt].v=v;
			E[cnt].w=w;
		}
		rep(i,1,k){
			rep(j,1,n){
				++cnt;
				E[cnt].u=n+i;
				E[cnt].v=j;
				E[cnt].w=cost[i][j];
			}
		}
		rep(i,1,n+k){
			fa[i]=i;
		}
		sort(E+1,E+cnt+1,cmp);
		ll ans=0;
		for(int i=1;i<=cnt;++i){
			int u=E[i].u,v=E[i].v,w=E[i].w;
			u=find(u),v=find(v);
			if(u==v)continue;
			fa[u]=v;
			ans+=w;
		}
		cout<<ans<<'\n';
		return 0;
	}
	vector<int> g;
	dfs(1,g);
	cout<<lst_ans<<'\n';
	return 0;
}

