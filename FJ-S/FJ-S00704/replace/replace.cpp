//解决部分
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>graph(2000010);
int n,m,k;
bool visited[1000010]={};
long long minval=1e8+5;
int dfs(int now,int k,int tcost){//遍历最多只要n-1次 
	if(now<=n)visited[now]=1;
	if(k==1){
		for(int i=1;i<=n;++i){
			if(visited[i]==0){
				return 0;
			}
		}
		if(tcost<minval)minval=tcost;
	}
	for(int i=0;i<graph[now].size();++i){
		dfs(graph[now][i].first,k--,tcost+graph[now][i].second);
	}
	visited[now]=0;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	cin>>n>>m>>k;
	int t;
	for(int i=0;i<m;++i){
		int temp1,temp2,temp3;
		cin>>temp1>>temp2>>temp3;
		graph[temp1].push_back({temp2,temp3});
		graph[temp2].push_back({temp1,temp3});
	}
	for(int i=1;i<=n;++i){
		cin>>t;
		for(int j=1;j<=m;++j){
			cin>>t;
			graph[m+1].push_back({j,t});
			graph[j].push_back({m+1,t});
		}
	}
	visited[1]=1;
	for(int i=0;i<graph[1].size();++i){
		dfs(graph[1][i].first,m--,graph[1][i].second);
	}
	cout<<minval;
	return 0;
} 
