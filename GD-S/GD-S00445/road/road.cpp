#include<bits/stdc++.h> 
using namespace std;
struct T{
	int v;
	long long w;
	int b=-1;
};
int q[1000002],top=0,till=0;
vector<T>e[10015];
void dijtra(int a,int b){
	q[till]=1;
	till++;
	while(q[top]!=0){
		while(e[a][q[top]].b==-1 or e[a][q[top]].b!=0){
			top++;
		}
		if(e[a][q[top]].b==0){
			return;
		}
		
		int now=q[top];
		for (int i=1;i<=e[a].size();i++){
			int w=e[a][i].w;
			int v=e[a][i].v;
			if(e[a][now].w+w<e[a][i].w){
				e[a][i].w=e[a][now].w+w;
				q[till++]=e[a][i].v;
			}
		}
		e[a][now].b=1;
	}
	
	
}
int n,m,k,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			e[i].push_back({j,1000000000,-1});
			e[j].push_back({i,1000000000,-1});
		}
	}
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w,-1});
		e[v].push_back({u,w,-1});
	}
	for (int i=1;i<=k;i++){
		int u,v,w[n+1];
		cin>>w[0];
		for (int j=1;j<=n;j++){
			cin>>w[j];
			e[j].push_back({i+n,w[0]+w[j],-1});
			e[i+n].push_back({j,w[0]+w[j],-1});
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			dijtra(i,j);
			ans+=e[i][j].w;
		} 
	}
	cout<<ans;
	return 0;
}
