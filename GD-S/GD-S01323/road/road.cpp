#include<bits/stdc++.h>
using namespace std;
struct ede{
	int u,v,w; 
}; 
bool is_DAG(vector<vector<bool> > edges,int n){
	bool flag=1;
	while(flag){
		flag=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					if(edges[i][l]&&edges[j][l]){
						flag=1;
						if(edges[i][j]==1) return 0;
						edges[i][j]=1;
						edges[j][i]=1;
					}
				}
			}
		}
	}
	return 1;
}
int dfs(int n,int k,vector<vector<int> > edge,vector<vector<int> > a,vector<vector<vector<bool> > > spend_in_countryside){
	vector<ede>  edg;  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				if(i!=j) edge.push_back({i,j,edge[i][j]}); 
		} 
	}
	return  ede[2].w; 
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k; 
	vector<vector<int> > edge(n+1,vector<int>(n+1,INT_MAX/2));
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[u][v]=w;
		edge[v][u]=w;
	} 
	vector<int> c(n+1);
	vector<vector<int> > a(n+1,vector<int>(n+1));
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<vector<bool> > > spend_in_countryside(n+1,vector<vector<bool> >(n+1,vector<bool>(k+1,0)));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=0;l<=n;l++){
				edge[i][l]=min(edge[i][l],edge[i][j]+edge[j][l]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int mi=INT_MAX,mic=-1;
			for(int l=1;l<=k;l++){
				if(a[l][i]+c[l]+a[l][j]<mi){
					mic=l;
					mi=a[l][i]+c[l]+a[l][j];
				}
			}
			spend_in_countryside[i][j][mic]=1;
		}
	}
	cout<<dfs(n,k,edge,a,spend_in_countryside);
	return 0;
} 
