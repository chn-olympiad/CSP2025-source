#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
};
vector<edge>e[20005];
int n,m,k,ans,cnt,res=1,vis[20005];
int c[20];
queue<int>q;
void Prim(){
	int cy=0;
	while(q.size()-cy<n){
		int u=q.front();
		q.pop();
		int mn=0;
		for(int i=1;i<e[u].size();i++){
			if(e[u][i].w<e[u][mn].w&&vis[e[u][i].v]==0){
				mn=i;
				q.push(e[u][mn].v);
				q.push(u);
				ans+=e[u][mn].w;
				if(e[u][mn].v>n){
					cy++;
				}
				vis[e[u][mn].v]=1;
				break;
			}
			
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=n;
	for(int i=1;i<=m;i++){
		int x;
		edge y;
		edge z;
		cin>>x>>y.v>>y.w;
		z.v=x;
		z.w=y.w;
		e[x].push_back(y);
		e[y.v].push_back(z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			edge y;
			edge z;
			y.v=j;
			cin>>y.w;
			z.v=cnt+1;
			z.w=y.w;
			e[++cnt].push_back(y);
			e[j].push_back(z);
		}
	}
	q.push(1);
	vis[1]=1;
	Prim();
	cout<<ans;
	return 0;
}//rp++