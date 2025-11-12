#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;//prim 
const int inf=1e9; 
struct node{
	int v,w;
};
vector<node> edge[N];
int c[20];
int a[20][N];
int vis[N],dis[N];
int n,m,k;
//dis[i]表示i点到已选点集的距离 
int prim(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	long long ans=0;
	for(int step=1;step<=n;step++){
		int mi=1e9,id=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&dis[i]<mi){
				mi=dis[i];
				id=i;
			}
		}
		vis[id]=1;
		ans+=mi;
		int len=edge[id].size();
		for(int i=0;i<len;i++){
			int to=edge[id][i].v;
			if(vis[to]==0&&edge[id][i].w<dis[to]){
				dis[to]=edge[id][i].w;
			}
		}
	/*	for(int i=1;i<=n;i++){
			cout<<dis[i]<<" ";
		}cout<<" | ";
		cout<<ans<<"\n";*/
	}//cout<<'\n';
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=j){
				u=i; v=j;
				for(int x=1;x<=k;x++){
				//	cout<<"c:"<<c[x]<<" ";
					w=c[x]+a[x][i]+a[x][j];
					edge[u].push_back({v,w});
					edge[v].push_back({u,w});
				}//cout<<'\n';
				
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<i<<":";
		int len=edge[i].size();
		for(int j=0;j<len;j++){
			cout<<"("<<edge[i][j].v<<","<<edge[i][j].w<<") ";
		}
		cout<<'\n';
	}*/
	cout<<prim();
	return 0;
} 
