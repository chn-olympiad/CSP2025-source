#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>graph(2000010);
int n,m,k;
bool visited[2000010]={};
long long minval=1e8+5;
int dfs(int now,long long tcost){//遍历最多只要n-1次 
	if(now<=n)visited[now]=1;

	for(int i=1;i<=n;++i){
		if(visited[i]==0){
			for(int i=0;i<graph[now].size();++i){
				dfs(graph[now][i].first,tcost+graph[now][i].second);
			}
			visited[now]=0;
			return 0;	
		}
	}
	visited[now]=0;
	if(tcost<minval)minval=tcost;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	int t;
	for(int i=0;i<m;++i){
		int temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		graph[temp1].push_back({temp2,temp3});
		graph[temp2].push_back({temp1,temp3});
	}
	for(int i=1;i<=k;++i){
		cin>>t;
		for(int j=1;j<=n;++j){
			cin>>t;
			graph[n+i].push_back({j,t});
			graph[j].push_back({i+n,t});
		}
	}
	visited[1]=1;
	queue<pair<int,int>>q;
	q.push({0,1});
	while(!q.empty){
		int c=q.front;
		q.pop();
		if(visited[c.second]==1){
			continue;
		}
		visited[c.second]=1;
		int t=0;
		for(int i=0;i<n+1;++i){
			if(visited[i]==0)t=1;
		}
		if(t==0&&c.first<minval){
			minval=c.first;
		}
		for(int i=0;i<graph[c.second].size();++i){
			
		}
	}

	cout<<minval;
	return 0;
} 
