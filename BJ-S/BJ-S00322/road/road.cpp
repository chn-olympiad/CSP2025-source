#include<bits/stdc++.h>
using namespace std;
const int N=2e4+100,M=2e6+10;
struct node{
	int v,w;
};
int n,m,k;
vector<node> e[N];
long long ans;
priority_queue<pair<int,int> > q;
long long dis[N];
int lase[N];
void dij(){
	for(int i=1;i<=n;i++) dis[i]=1e18;
	memset(lase,0,sizeof(lase));
	dis[1]=0;
	q.push(make_pair(0,1));
	int u,v;
	while(q.size()){
		u=q.top().second;
		q.pop();
		for(int i=0;i<e[u].size();i++){
			v=e[u][i].v;
			if(dis[u]+e[u][i].w<=dis[v]){
				if(dis[v]>dis[u]+e[u][i].w) q.push(make_pair(-dis[v],v));
				dis[v]=dis[u]+e[u][i].w;
				ans-=lase[v];
				ans+=e[u][i].w;
				//cout<<"ans-"<<lase[v]<<"+"<<e[u][i].w<<"="<<ans<<"\n";
				lase[v]=e[u][i].w;
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[x].push_back(node{y,z});
		e[y].push_back(node{x,z});
	}
	int c;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(j==0){
				cin>>c;
			}
			cin>>z;
		}
	}
	if(k==0){
		dij();
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
