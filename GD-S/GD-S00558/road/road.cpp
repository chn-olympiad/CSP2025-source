#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pir pair<int,int>
const int N=1e6;
const ll Mod=1;
struct goose{
	int now,far,cnt;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<pair<int,int>>> maze(n+1);
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		maze[u].push_back({v,w});
		maze[v].push_back({u,w});
	}
	priority_queue<pir,vector<pir>,greater<pir>> q;
	vector<bool> vis(n+1);
	vector<int> ans(n+1,1e9);
	int sum=0;
	q.push({0,1});
	ans[1]=0;
	while(q.size()){
		int far=q.top().first;
		int now=q.top().second;
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(auto [i,j]:maze[now]){
			int k=j+far;
			if(k<ans[i]){
//				if(vis[now]==0) ans+=k;
				ans[i]=k;
				q.push({k,i});
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,ans[i]);
//		cout<<ans[i]<<' ';
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
