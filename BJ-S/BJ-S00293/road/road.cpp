#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
int n,m,k;
vector<pair<int,int>> g[10010];
int pay[10],ve[10][10010];
priority_queue<pair<int,int>> q;
bool f[10010];
int len[10010];
void k0run(){
	len[1]=0;
	q.push({0,1});
	f[1]=1;
	while(!q.empty()){
		pair<int,int> x=q.top();
		q.pop();
		for(int i=0;i<g[x.second].size();i++){
			if(f[g[x.second][i].second]==1){
				continue;
			}
			if(len[g[x.second][i].second]>g[x.second][i].first){
				q.push({g[x.second][i].first,g[x.second][i].second});
				len[g[x.second][i].second]=g[x.second][i].first;
			}
			f[g[x.second][i].second]=1;
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=len[i];
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(len,0x3f,sizeof len);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
	}
	for(int i=1;i<=k;i++){
		cin>>pay[i];
		for(int j=1;j<=n;j++){
			cin>>ve[i][j];
		}
	}
	k0run();
	fclose(stdin);
	fclose(stdout);
	return 0;
}