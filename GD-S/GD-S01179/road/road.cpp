#include <bits/stdc++.h>
using namespace std;
int n,m,k,qwq1,qwq2,qwq3,ans = 0,dist[100034],cnt=1,i;
bool flag = 1,visited[100034];
vector<vector<pair<int,int>>> g(1007834);
vector<int> c(34);
void d(int start,int n){
	fill(dist+1,dist+1+n,1e8);
	queue<int> q;
	visited[start] = 1;
	dist[start] = 0;
	q.push(start);
	while(!q.empty()){
		cnt++;
		int current_dist = dist[q.front()];
		int u = q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			if(!visited[g[u][i].first]){
				visited[g[u][i].first] = 1;
				if(dist[g[u][i].first] > current_dist){
					dist[g[u][i].first] = (current_dist + g[u][i].second);
					ans += g[u][i].second;
					//printf("%d ",g[u][i].first);
					q.push(g[u][i].first);
				}
			}
		}
	}
	//printf("\n");
	//printf("\n");
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&qwq1,&qwq2,&qwq3);
		g[qwq1].push_back(make_pair(qwq2,qwq3));
		g[qwq2].push_back(make_pair(qwq1,qwq3)); //Ë«Ïò 
	}
	for(int t=0;t<k;t++){
		scanf("%d",&c[t]);
		if(flag && c[t] != 0) flag = 0;
		for(int j=0;j<n;j++){
			scanf("%d",&qwq3);
			if(flag && qwq3 != 0) flag =0;
			dist[t+n] = c[t];
			g[j].push_back(make_pair(t+n,qwq3));
			g[t+n+1].push_back(make_pair(j,qwq3)); //Ë«Ïò 
		}
	}
	if(flag){
		printf("0");
		return 0;
	}
	d(1,n);
	printf("%d",ans);
	return 0;
}
