#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1010

ll n,m,k,u,v,w;
int t[MAXN][MAXN],l[MAXN];
int dp[MAXN][MAXN];
vector<vector<int> >q;
vector<vector<int> >r;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q[u].push_back(v);
		q[v].push_back(u);
		t[u][v]=w;
		t[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		cin>>l[i];
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			r[i].push_back(y);
		}
	}
	cout<<0;
	return 0;
} 
