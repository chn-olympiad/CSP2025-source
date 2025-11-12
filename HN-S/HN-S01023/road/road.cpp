#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k,st[N],ans,d[N];
vector<pair<int,int>> a[N];
int bfs(){
	queue<int> q;
	q.push(1);
	st[1]=1;
	d[1]=0;
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=0;i<a[t].size();i++){
			if(st[a[t][i].first]) continue;
			st[a[t][i].first]=1;
			q.push(a[t][i].first);
			d[a[t][i].first]=min(d[a[t][i].first],a[t][i].second);
			for(int j=0;j<a[a[t][i].first].size();j++){
				if(a[a[t][i].first][j].first) continue;
				d[a[a[t][i].first][j].first]=min(d[a[a[t][i].first][j].first],a[a[t][i].first][j].second);
			}
		}
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		d[i]=10000000;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	if(k==0){
		bfs();
		for(int i=1;i<=n;i++){
			ans+=d[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		int c,x;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>x;
		}
	}
	
	return 0;
}
