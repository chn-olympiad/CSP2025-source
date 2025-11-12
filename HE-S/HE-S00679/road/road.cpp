#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

typedef pair<int,int> PII;

struct Node{
	int z,x,y;
	bool operator< (const struct Node &t) const{
		return z < t.z;
	}
}p[N];

int f_[N];
vector<PII> e[N];

int find(int u){
	if(f_[u] != u) f_[u] = find(f_[u]);
	return f_[u]; 
}

int f[N][20],q[N][20];
int dfn[N];

void dfs(int u){
	for(int i = 1;i < 20;i++){
		f[u][i] = f[f[u][i - 1]][i - 1];
		q[u][i] = max(q[f[u][i - 1]][i - 1],q[u][i - 1]);
	}
	for(int i = 0;i < e[u].size();i++){
		int u1 = e[u][i].second,u2 = e[u][i].first;
		if(f[u][0] == u1) continue;
		f[u1][0] = u;
		q[u1][0] = u2;
		dfn[u1] = dfn[u] + 1;
		dfs(u1);
 	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		p[i] = {z,x,y};
	}
	sort(p + 1,p + 1 + m);
	for(int i = 1;i <= n;i++)
		f_[i] = i;
	int ans = 0;
	for(int i = 1;i <= m;i++){
		int x = p[i].x,y = p[i].y,z = p[i].z;
		int a1 = find(x),b1 = find(y);
		if(a1 != b1){
			f_[a1] = f_[b1];
			e[x].push_back({z,y});
			e[y].push_back({z,x});
			ans += z;
		}
	}
	cout<<ans<<'\n';
//	f[1][0] = 1;
//	dfs(1);
//	int ans = 0;
//	
//	for(int i = 0;i < (1 << k);i++){
//		for(int j = 0;j < k;j++){
//			
//		}
//	}
return 0;
}
