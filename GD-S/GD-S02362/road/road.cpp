#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long
#define pii pair<int,int>
#define N 10005
#define INF 0x3f3f3f3f
using namespace std;

int n,m,k,cnt,ans;
bool f[N];
vector<pii> a[N],b[N];
inline void prim() {
	
	int now=1;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	while(cnt<n-1) {
//			cout<<now<<endl;
		cnt++;
		f[now]=1;
		for(int i=0;i<b[now].size();i++) {
			if(f[b[now][i].first]) continue;
			q.push({b[now][i].second,b[now][i].first});
		}
		while(!q.empty()&&f[q.top().second]) q.pop();
		now=q.top().second;
		ans+=q.top().first;
		a[now].push_back({q.top().second,q.top().first});
		a[q.top().second].push_back({now,q.top().first});
//			cout<<q.top().first<<endl;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		b[u].push_back({v,w});
		b[v].push_back({u,w});
	}
	// 最小生成树 
	prim();
	cout<<ans;
	cout.flush();
	return 0;
}
/*
4 4 0
1 2 2
1 3 3
2 3 2
1 4 4
I love ccf pls give me 100 pts
*/

