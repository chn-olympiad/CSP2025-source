#include<bits/stdc++.h>
using namespace std;
bool vis[10005];
int a[10005];
int G[10005][10005];
int N[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	memset(G,0x3f,sizeof G);
	memset(N,0x3f,sizeof N);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		int u;
		cin >> u;
		for(int j = 1;j <= n;j++){
			int v;
			cin >> v;
			N[u][j] = v;
			N[j][u] = v;
		}
	}
	if(k == 0){
		int sum = 0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		memset(a,0x3f,sizeof a);
		q.push({0,1});
		for(int i = 1;i <= n;i++){
			int x = q.top().second;
			a[x] = q.top().first;
			q.pop();
			vis[x] = 1;
			for(int j = 1;j <= n;j++){
				if(G[x][j] == 0x3f3f3f3f or vis[j]) continue;
				if(G[x][j] + a[x] < a[j])a[j]=G[x][j] + a[x];
				q.push({a[j],j});
			}
		}
		for(int i = 2;i <= n;i++) sum += a[i];
		cout << sum;
	}else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
