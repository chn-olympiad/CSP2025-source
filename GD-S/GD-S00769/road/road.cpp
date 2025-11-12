#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5,M = 1e6 + 5;
int n,m,k,c[20],a[20][N],f[N],ans,res,b[20],tot,dp[N][20];
vector<int>g[N],w[N];
struct node{
	int x,y,z;
}t[N];
bool cmp(node x,node y){
	return x.z < y.z;
}
int find(int x){
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
void dfs(int x,int fa){
	for (auto y : g[x]){
		if (y == fa) continue;
		dfs(y,x);
		 
	}
}
void slv(){
	dfs(1,0);
}
int main(){
//	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)f[i]=i; 
	for (int i = 1;i <= m;i++){
		cin >> t[i].x >> t[i].y >> t[i].z;
	}
	sort(t+1,t+m+1,cmp);
	for (int i = 1;i <= m;i++){
		int x = find(t[i].x),y = find(t[i].y);
		if (x != y){
			g[t[i].x].push_back(t[i].y);
			g[t[i].y].push_back(t[i].x);
			w[t[i].x].push_back(t[i].z);
			w[t[i].y].push_back(t[i].z);
			f[y] = x;
			ans += t[i].z;
		}
	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	if (k == 0){
		cout << ans << '\n';
		return 0;
	}
	for (int i = 0;i < (1 << k);i++){
		int add = 0;tot = 0;
		for (int j = 0;j < k;j++) if (i & (1 << j)) add += c[j+1],b[++tot] = j+1;
		if (add >= ans) continue;
		res = 0;
		slv();
		ans = min(ans,res + add); 
	}
	cout << ans << '\n';
	return 0;
}






