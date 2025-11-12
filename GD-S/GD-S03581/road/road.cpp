#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=b;i>=(int)a;i--)
const int N=1e4+10;
const ll inf=1e9+10;
const ll mod=1e9+7;
using Vl=vector<ll>;
using PI=array<ll,3>;
ll n,m,k,fa[N],ans=0,w[11],to[11][N],D[N];
PI e[N*114];
inline int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
bool pf=1,vis[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	FOR(i,1,m) cin>>e[i][1]>>e[i][2]>>e[i][0];
	if(k==0){
		FOR(i,1,n) fa[i]=i;
		sort(e+1,e+m+1);int cte=0;
		FOR(i,1,m){
			int x=fd(e[i][1]),y=fd(e[i][2]),w=e[i][0];
			if(x==y) continue;
			ans+=w;fa[x]=y;
			if(++cte==n-1) break;
		}
		cout<<ans<<'\n';return 0;
	}
	FOR(i,1,k){
		cin>>w[i];
		FOR(j,1,n) cin>>to[i][j]; 
		if(w[i]) pf=0;
	}
	vector<Vl> a(n+1,Vl(n+1,inf));
	if(pf){
		FOR(i,1,k){
			FOR(x,1,n){
				FOR(y,1,n){
					a[x][y]=min(a[x][y],to[i][x]+to[i][y]),a[y][x]=min(a[y][x],to[i][x]+to[i][y]);
				}
			}
		}
		FOR(i,1,m) a[e[i][1]][e[i][2]]=min(a[e[i][1]][e[i][2]],e[i][0]),a[e[i][2]][e[i][1]]=min(a[e[i][2]][e[i][1]],e[i][0]);
		priority_queue<array<ll,2> > q;q.push({0,1});
		fill(D,D+n+1,inf);D[1]=0;
		while(!q.empty()){
			auto tp=q.top();q.pop();
			int u=tp[1];
			if(vis[u]) continue;
			vis[u]=1;ans-=tp[0];
			FOR(i,1,n) if(D[i]>a[u][i]&&u!=i) q.push({-a[u][i],i}),D[i]=a[u][i];
		}
		cout<<ans<<'\n';return 0;
	}
	ans=inf;
	FOR(S,0,(1<<k)-1){
		ll res=0;
		FOR(i,1,n) FOR(j,1,n) a[i][j]=inf;
		FOR(i,1,k){
			if((S>>(i-1))&1){
				res+=w[i];
				FOR(x,1,n){
					FOR(y,1,n){
						a[x][y]=min(a[x][y],to[i][x]+to[i][y]),a[y][x]=min(a[y][x],to[i][x]+to[i][y]);
					}
				}
			}	
		}
		FOR(i,1,m) a[e[i][1]][e[i][2]]=min(a[e[i][1]][e[i][2]],e[i][0]),a[e[i][2]][e[i][1]]=min(a[e[i][2]][e[i][1]],e[i][0]);
		priority_queue<array<ll,2> > q;q.push({0,1});
		fill(D,D+n+1,inf);fill(vis,vis+n+1,0);D[1]=0;
		while(!q.empty()){
			auto tp=q.top();q.pop();
			int u=tp[1];
			if(vis[u]) continue;
			vis[u]=1;res-=tp[0];
			FOR(i,1,n) if(D[i]>a[u][i]&&u!=i) q.push({-a[u][i],i}),D[i]=a[u][i];
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
