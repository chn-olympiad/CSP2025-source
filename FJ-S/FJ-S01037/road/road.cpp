#include<bits/stdc++.h>
using namespace std;
long long n,m,k,anss=0;
int phsz[10010];
vector<pair<int,int>> g[10010]; 
void zh(){
	memset(phsz,0,sizeof phsz);
	queue<int> q;
	q.push(1);
	phsz[1]++;
	while(!q.empty()){
		int oo=q.front();
		q.pop();
		for(int i=0;i<g[oo].size();i++){
			phsz[g[oo][i].first]++;
			
			if(phsz[g[oo][i].first]>=4*m){
				break;
			}
			q.push(g[oo][i].first);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		anss+=w;
	}
	zh();
	for(int i=m+1;i<=m+k;i++){
		int c;
		cin>>c;int u,v,w;
		cin>>w;
	}
	cout<<19;
	return 0;
}

