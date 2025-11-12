#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
const int N=1e4+20;
int n,m,k,nc[15],dp[N],ans,s[N],vis[N];
vector<pair<int,int> > vr[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vr[u].push_back({v,w});
		vr[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>nc[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			vr[n+i].push_back({j,w});
			vr[j].push_back({n+i,w});
		}
	}
	for(int i=1;i<=n+k;i++){
		dp[i]=1e18;
	}
	dp[1]=0;
	vis[1]=1;
	q.push({0,1});
	while(q.size()){
		int now=q.top().second;
		q.pop();
		int sum=0;
		for(int i=0;i<vr[now].size();i++){
			int v=vr[now][i].first;
			int w=vr[now][i].second;
			if(dp[v]>dp[now]+w){
				if(now>n and vis[now]==0){
					sum+=(dp[v]-dp[now]-w);
				}
				else{
					if(v>n){
						
						s[v]=w;
						dp[v]=dp[now]+w;
						q.push({dp[v],v});
					}
					else{
						ans-=s[v];
						dp[v]=dp[now]+w;
						ans+=w;
						s[v]=w;
						vis[v]=1;
						q.push({dp[v],v});
					}
				}
			}
		}
		if(now>n and vis[now]==0){
			if(sum>s[now]+nc[now-n]){
				vis[now]=1;
				ans+=s[now]+nc[now-n];
				for(int i=0;i<vr[now].size();i++){
					int v=vr[now][i].first;
					int w=vr[now][i].second;
					if(dp[v]>dp[now]+w){
						ans-=s[v];
						dp[v]=dp[now]+w;
						ans+=w;
						s[v]=w;
						vis[v]=1;
						q.push({dp[v],v});
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/