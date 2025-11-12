#include<bits/stdc++.h>
#define ll long long
const int N = 1e4+5;
const int M = 1e6+5;
using namespace std;

ll n,m,k,cnt,ans;
ll u,v,w,h[N];
struct edge{
	ll from,to,cost,next;
}e[M];

ll c[N],a[11][10001];
long long vis[N];
bool f[N];

void init(ll u,ll v,ll w){
	e[++cnt].to=v;
	e[cnt].cost=w;
	e[cnt].from=u;
	e[cnt].next=h[u];
	h[u]=cnt;
}

queue<ll> q;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		init(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=m;j++){
			if(c[i]+a[i][e[j].to]+a[i][e[j].from]<e[j].cost){
				e[j].cost=c[i]+a[i][e[j].to]+a[i][e[j].from];
			}
		}
	}
	for(int i=1;i<=n;i++)vis[i]=1e18;
	q.push(1);
	f[1]=1;
	vis[1]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		f[x]=0;
		for(int i=h[x];i;i=e[i].next){
			if(vis[e[i].to]>vis[i]+e[i].cost){
				vis[e[i].to]=vis[i]+e[i].cost;
				if(!f[e[i].to]) q.push(e[i].to),f[e[i].to]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=vis[i];
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
