//GZ-S00161 贵阳市第一中学 张梁予 
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
int n,m,k,v[10005][10005],in[10005],vis[10005],dp[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		cin>>v[x][y];
		in[x]++,in[y]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==1) q.push(i);
	}
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto y:g[x]){
			dp[y]=min(dp[y],dp[x]+v[x][y]);
			in[y]--;
			if(in[y]==1) q.push(y);			
		}
	}
	cout<<dp[n];
	return 0;
}
