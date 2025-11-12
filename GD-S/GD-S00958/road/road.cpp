#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+2;
ll ans=0x3f3f3f3f3f;

struct Node {
	int from,to,w;
};

bool operator <(const Node a,const Node b) {
	return a.w>b.w;
}

priority_queue<Node> q;
vector<int>dp(N);

int find_set(int x) {
	if(dp[x]==x) return x;
	else return dp[x]=find_set(dp[x]);
}

int kruskal(int n,ll st) {
	for(int i=1;i<=n;i++) dp[i]=i;
	int cnt=0;ll res=st;
	vector<bool>vis(n,0);
	while(!q.empty()) {
		if(cnt==n) break;
		Node t=q.top();
		q.pop();
		int t1=find_set(t.from),t2=find_set(t.to);
		if(t1==t2) continue;
		
		if(!vis[t.from]) cnt++;
		if(!vis[t.to]) cnt++;
		vis[t.from]=vis[t.to]=1;
		res+=t.w;
		if(res>=ans) return -1;
		dp[t1]=t2;
	}
	//cout<<n<<' '<<st<<' '<<res<<endl;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue<Node> q0;
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		q0.push({u,v,w});
	}
	
	vector<int>p(k+1);
	vector<vector<int>>w(k,vector<int>(n+1,0));
	for(int i=0;i<k;i++) {
		cin>>p[i];
		for(int j=1;j<=n;j++) cin>>w[i][j];
	}
	
	for(int s=0;s<(1<<k);s++) {
		ll now=0;
		int cnt=0;
		q=q0;
		for(int i=0;i<k;i++) {
			if(s&(1<<i)) {
				now+=p[i];cnt++;
				for(int j=1;j<=n;j++) {
					q.push({j,n+cnt,w[i][j]});
				}
			}
		}
		ll t=kruskal(n+cnt,now);
		if(t!=-1) ans=min(ans,t);
	}
	cout<<ans<<endl;
	return 0;
} 
