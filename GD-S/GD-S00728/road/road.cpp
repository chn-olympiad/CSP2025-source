#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

int n,m,k;
vector<pair<int,int>> G[10040]; 


bool vis[10040];
int S[10040];
int li[10040];
void solve(){
	for(int i=2;i<=n+k;i++){
		S[i]=inf;
	}S[1]=0;
	int N=0; 
	int u=1;
	while(1){
		vis[u]=1;
		if(u<=n){
			N++;
			if(N==n)break;
		}
		for(pair<int,int> p : G[u]){
			int v=p.first;
			int w=p.second;
			if(S[u]+w<S[v]){
				S[v]=S[u]+w;
				li[v]=w;
			}
		}int mi=inf;
		for(int i=1;i<=n+k;i++){
//			cout<<i<<" "<<S[i]<<" "<<vis[i]<<endl;
			if(S[i]<mi and vis[i]==0){
				mi=S[i];
				u=i;
			}
		}if(mi==inf)break;
	}int ans=0;
	for(int i=1;i<=n+k;i++){
		ans+=li[i];
	}cout<<ans;

	
}



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}for(int i=1,v;i<=k;i++){
		cin>>v;
		for(int j=1,u;j<=n;j++){
			cin>>u;
			if(v==0){
				G[n+i].push_back(make_pair(j,u));
				G[j].push_back(make_pair(n+i,u));
			}
		}
	}
	solve();
	
	
	
	
	return 0;
}
