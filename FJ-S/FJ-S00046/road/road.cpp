#include <bits/stdc++.h>
using namespace std;

long long ans = 1LL << 60,a[20][10010];
bool bol1[20],bol[10020];
int n,m,k;

vector <pair <int,int>> edges[10020];
priority_queue <pair <long long,int>,vector <pair <long long,int>>,greater <pair <long long,int>>> q;

void solve(){
	long long ans_ = 0;
	int len = q.size();
	while(len--){
		q.pop();
	}
	int cnt = 0;
	for(int i = 1;i <= k;i++){
		cnt -= bol1[i];
		ans_ += a[i][0] * bol1[i];
	}
	for(auto i : edges[1]){
		q.push({i.second,i.first});
	}
	while(!q.empty()){
		pair <int,int> num = q.top();
		q.pop();
		long long dd = num.first;
		int u = num.second;
		if(bol[u]){
			continue;
		}
		cnt++;
		bol[u] = true;
		ans_ += dd;
		if(cnt == n - 1){
			break;
		}
		for(auto v : edges[u]){
			if(!bol[v.first]){
				q.push({v.second,v.first});
			}
		}
	}
	if(cnt != n - 1){
		return ;
	}
	ans = min(ans,ans_);
	return ;
}

void dfs(int x){
	if(x == k + 1){
		memset(bol,false,sizeof(bol));
		bol[1] = true;
		solve();
		return ;
	}
	dfs(x + 1);
	bol1[x] = true;
	for(int i = 1;i <= n;i++){
		edges[n + x].push_back({i,a[x][i]});
		edges[i].push_back({n + x,a[x][i]});
	}
	dfs(x + 1);
	bol1[x] = false;
	for(int i = 1;i <= n;i++){
		edges[n + x].pop_back();
		edges[i].pop_back();
	}
	return ;
}

int main(){
	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	bool bol2 = true;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edges[u].push_back({v,w});
		edges[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",&a[i][0]);
		if(a[i][0] != 0){
			bol2 = false;
		}
		for(int j = 1;j <= n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j] != 0){
				bol2 = false;
			}
		}
	}
	if(bol2){
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
