#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e4+10,M=1e6+20;

int n,m,k,c[N],ans;
bool vis[N];
int g[N][N];
vector<int>st;

void prim(int cur){
	int minn=1e9,to;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			for(auto it:st){
				int dis;
				if(i>n){
					dis=c[i]+g[it][i];
				}else{
					dis=g[it][i];
				}
				if(dis<minn){
					minn=dis;
					to=i;
				}
			}
		}
	}
	st.push_back(to);
	ans+=minn;
	vis[to]=1;
	prim(to);
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(g,0x3f,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[n+i][j]=g[j][n+i]=w;
		}
	}
	vis[1]=1;
	st.push_back(1);
	prim(1);
	cout<<ans;
	
	return 0;
}
