#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4;
const int M=1e6;
const int K=10;
int n,m,k;
int u,v;
ll w;
int c[K+5];
ll a[K+5][N+5];
struct Edge{
	int u,v;
	ll w;
	int type;
	int next;
}e[((M<<1)<<4)+5];
int head[N+5],cnt;
void add(int u,int v,ll w,int type){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	e[cnt].type=type;
	head[u]=cnt;
	return ;
}
int zero;
ll val_zero;
ll ans=3e18;
struct Point{
	int v;
	ll w;
	bool operator <(Point b)const{
		return w>b.w;
	}
};
bitset<N+5> vis;

ll Prim(int p,int b){
	priority_queue<Point> q;
	vis=0;
	q.push({p,0});
	ll res=0;
	while(!q.empty()){
		int u=q.top().v;
		int qw=q.top().w;
		// cout<<u<<" with "<<q.top().w<<"\n";
		q.pop();
		if(vis[u])
			continue;
		res+=qw;
		vis[u]=1;
		// ++cnt;
		for(int i=head[u];i;i=e[i].next){
			if((!e[i].type)||((b>>e[i].type)&1)){
				int v=e[i].v;
				ll w=e[i].w;
				if(vis[v])
					continue;
				q.push({v,w});
			}
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w,0),add(v,u,w,0);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(!c[i]){
			zero|=(zero<<i);
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			add(n+i,j,a[i][j],i);
			add(j,n+i,a[i][j],i);
		}
	}
	ans=Prim(1,zero);
	if(clock()*1.0/CLOCKS_PER_SEC >=0.8){
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		ll res=0;
		for(int j=0;j<k;j++)
			if((i>>j)&1)
				res+=c[j+1];
		// cout<<"i="<<i<<"\n";
		res+=Prim(1,i<<1);
		// cout<<res<<"\n";
		ans=min(res,ans);
	}
	cout<<ans<<"\n";
	return 0;
}