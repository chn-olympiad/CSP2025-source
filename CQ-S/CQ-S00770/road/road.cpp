#include<bits/stdc++.h>
using namespace std;
int n,m,k,vi[11][10001];
vector<int>g[10011],w[10011];
long long Ans=0,dist[10011],inq[10011];
void SPFA(){
	queue<int>q;
	memset(dist,0x7f,sizeof dist);
	q.push(1);
	dist[1]=0;
	inq[1]=1;
	while(!q.empty()){
		int i=q.front();
		q.pop();
		inq[i]=0;
		for(int k=0;k<(int)g[i].size();k++){
			int j=g[i][k],c=w[i][k];
			if(dist[j]>dist[i]+c){
				dist[j]=dist[i]+c;
				if(!inq[j]){
					inq[j]=1;
					q.push(j);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int u,v,c,i=1;i<=m;i++){
		cin>>u>>v>>c;
		g[u].push_back(v),g[v].push_back(u),w[u].push_back(c),w[v].push_back(c);
	}
	for(int s,i=1;i<=k;i++){
		cin>>s;
		if(s==0 || s==1){
			for(int v,j=1;j<=n;j++){
				cin>>v;
				g[m+i].push_back(j),g[j].push_back(m+i),w[m+i].push_back(v),w[j].push_back(v);
			}
		}
		else for(int j=1;j<=n;j++) cin>>vi[i][j];
	}
	SPFA();
	for(int i=1;i<=n;i++) Ans=max(Ans,dist[i]);
	cout<<Ans+w[n][3];
	return 0;
}
