#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int n,m,k;
const int M=3e6+10;
const int N=1e4+1e3;
struct node{
	int nxt,to,dis;
}e[M];
int h[N],cnt;
void add(int u,int v,int w){
	e[++cnt].nxt=h[u];
	e[cnt].to=v;
	e[cnt].dis=w;
	h[u]=cnt;
}
#define pii pair<int,int>
priority_queue<pii>q;
int dis[N];bool vis[N];
#define fi first
#define se second
#define mp make_pair
int ans;
int c[N],a[N][N];
int res=1e18;
void prim(int s){
	while(!q.empty())q.pop();
	For(i,0,n)dis[i]=1e18;
	For(i,0,n)vis[i]=0;
	dis[s]=0;
	q.push(mp(0,s));
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		if(vis[u])continue;
		ans+=dis[u];
//		cout<<u<<" "<<dis[u]<<"\n";
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			int w=e[i].dis;
			if(dis[v]>w){
				dis[v]=w;
				q.push(mp(-dis[v],v));
			}
		}
	}
}
int th[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,m){
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
	}
//	prim();cout<<ans;
	For(i,0,n)th[i]=h[i];
	int cnt0=cnt;
	For(i,1,k){
		cin>>c[i];
		For(j,1,n)cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		ans=0;int num=0;
		For(j,1,k){
			bool f=((i>>(j-1))&1);
			if(f==0)continue;
			num++;
			ans+=c[j];
			For(x,1,n){
				int w=a[j][x];
				add(0,x,w);add(x,0,w);
				//0->1~n w
			}
		}
		if(num)prim(0);
		else prim(1);
		res=min(res,ans);
		cnt=cnt0;
		For(i,0,n)h[i]=th[i];
	}
	cout<<res;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4


