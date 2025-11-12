#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
const int N=100006;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
int a[10][1000001];
int c[10];
struct edge{
	int from,to;
	ll w;
	int vis=0;
};
int u,v,ww;
struct node{
	int id;
	ll n_dis;
	bool operator < (const node &a)const{return a.n_dis>n_dis;}
};
vector<edge> e[N];
ll dis[N];
bool done[N];
ll ans=0;
void dijk(int s){
	for(int i=1;i<=n;i++){dis[i]=INF;done[i]=false;}
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,dis[s]});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(done[u.id])continue;
		done[u.id]=true;
		for(int i=0;i<e[u.id].size();i++){
			edge y=e[u.id][i];
			if(done[y.to])continue;
			if(dis[y.to]>y.w+u.n_dis){
				dis[y.to]=y.w+u.n_dis;
				q.push({y.to,dis[y.to]});
				if(e[u.id][i].vis==0){
					e[u.id][i].vis=1;
					ans+=e[u.id][i].w;
				}
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&ww);
		e[u].push_back({u,v,ww});
		e[v].push_back({v,u,ww});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i-1]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i-1][j]);
	}
	
	dijk(1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
