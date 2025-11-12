#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d[10005],result,ans,c[15],vg[15][10005];

vector<pair<int,int>> g[10050];

int Find(int x){
	if(d[x]!=x)return Find(d[x]);
	return x;
}

void merge(int a,int b){
	a = Find(a),b = Find(b);
	d[a] = b;
}

struct road{
	int u,v,w;
	bool operator<(const road &W)const{
		return w>W.w;
	}
};

void solve(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)d[i]=i;
	priority_queue<road>q;
	int mnu=1000000,mnv=1000000,mnw=10000000000;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
		if(c<mnw)mnu=a,mnv=b,mnw=c;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> vg[i][j];
		}
	}
	
	q.push({mnu,mnv,mnw});
	result = 0;
	while(q.size()>0){
		road r = q.top();
		q.pop();
		if(Find(r.u)==Find(r.v))continue;
		result += r.w;
		merge(r.u,r.v);
		int l=g[r.u].size();
		for(int i=0;i<l;i++)if(g[r.u][i].first!=r.v)q.push({r.u,g[r.u][i].first,g[r.u][i].second});
		l=g[r.v].size();
		for(int i=0;i<l;i++)if(g[r.v][i].first!=r.u)q.push({r.v,g[r.v][i].first,g[r.v][i].second});
	}
	result = max(result,ans);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	
	int T=1;
	while(T--){
		solve();
	}
	
	return 0;
}
