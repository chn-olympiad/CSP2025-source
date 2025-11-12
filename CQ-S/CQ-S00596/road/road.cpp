#include <bits/stdc++.h>
using namespace std;
//期望 16 
vector <pair<long long,long long> > g[10100];
long long n,m,k,u,v,w;
long long vis[10100];
long long c[11][10100];
pair <long long,pair<long long,long long> > q[10100];
long long Q;
long long sum;
void dfs(){
	priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long> > >,greater<pair<long long,pair<long long,long long> > > > que;
	que.push({0,{0,1}});
	while(!que.empty()){//O(mlogm+n)~=2*10^7
		long long now=que.top().second.second;
		if(vis[now]==1){
			que.pop();continue;
		}
		vis[now]=1;
		long long fromm=que.top().second.first;
		if(fromm!=0)  q[++Q]={fromm,{now,que.top().first}};
		sum+=que.top().first;
		que.pop();
		for(pair<long long,long long> p:g[now]){
			long long to=p.second,cost=p.first;
			if(vis[to]==0){
				que.push({cost,{now,to}});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("road.in","r",stdin);	
	freopen("road.out","w",stdout);	
	cin >> n >> m >> k;
	for(long long i=1;i<=m;i++){
		cin >> u >> v >> w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			cin >> c[i][j];
		}
	}
	if(k==0){//预计得分：16 
		dfs();
		cout << sum;	
	}
	else{
		dfs();sum=0;
		for(long long i=1;i<=Q;i++){
			long long to=q[i].second.first;
			long long from=q[i].first;
			for(long long j=1;j<=k;j++){
				if(q[i].second.second>c[j][from]+c[j][to]){
					q[i].second.second=c[j][from]+c[j][to];
				}
			}
			sum+=q[i].second.second;
		}
		cout << sum;
	}
	return 0;
}
/*
5 6 0 
1 5 4
1 4 1
3 4 2
2 3 2
4 5 3
1 2 2
*/
