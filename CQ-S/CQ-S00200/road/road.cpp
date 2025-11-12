#include<bits/stdc++.h>
#define int long long
using namespace std;
//int d[20][11451];
vector<pair<int,int> > r[1145141];
int n,m,k,vis[10010],cnt,ans;
priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int>> > q;
void bfs(){
	q.push({1,0});
	while(!q.empty()){
		int x=q.top().first,y=q.top().second;
		q.pop();
		if(vis[x]){
			ans=min(ans,y); 
			continue;
		}
		vis[x]=1;
		for(int i=0;i<r[x].size();i++){
			y+=r[x][i].second;
			if(!vis[r[x][i].first]) cnt++;
			q.push({r[x][i].first,y});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r[u].push_back({v,w});
		r[v].push_back({u,w}); 
		ans+=w;
	}
	cout<<ans;
//	for(int i=1;i<=k;i++){
//		int cj;
//		cin>>cj;
//		d[i][1]=cj;
//		for(int j=1;j<=n;j++){
//			int xx;
//			cin>>xx;
//			d[i][j+1]=xx;
//		}
//	} 
//	if(k==0){
//		bfs();
//		cout<<ans;
//		for(int i=1;i<=n;i++){
//			dis[i]=0x3f3f3f3f;
//		}
//		q.push({0,1});
//		dis[1]=0;
//		while(!q.empty()){
//			long long x=q.top().first,d=q.top().second;
//			q.pop(); 
//			for(int i=0;i<r[d].size();i++){
//				if(dis[r[d][i].first]>r[d][i].first){
//					dis[r[d][i].first]=r[d][i].first;
//				}q.push({r[d][i].first,r[d][i].second});
//			}
//		}
//		ans=r[d]
//	}
	return 0;
}
/*
4 3 0
1 4 6
2 3 7
1 3 2
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
