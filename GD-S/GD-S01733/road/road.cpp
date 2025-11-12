#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int INF = 1e9 + 10;
int n,m,k;
int w[N][N];
struct node{
	int to,w;
};
vector <node> e[N];
int c[N][N];
int f[N],vis[N],num[N][N],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(num,INF,sizeof num);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		f[i] = i;
	for(int i = 1;i <= n;i++){
		int u,v,ww;
		cin >> u >> v >> ww;
		w[u][v] = w[v][u] = ww;
		e[u].push_back({v,ww});
		e[v].push_back({u,ww});
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i][0];
		for(int j = 1;j <= n;j++){
			cin >> c[i][j];
			if(i == j){
				e[i].push_back({j,c[i][0]});
				continue;
			}
			e[i].push_back({j,c[i][j]});
		}
	}
	for(int i = 1;i <= n;i++){
		for(auto v : e[i]){
			int now = v.to;
			int ww = v.w;
			if(now == i)
				continue;
			if(c[i][now] == 0)
				num[i][now] = ww;
			else
				num[i][now] = min(ww,c[i][now] + c[i][0]);
		}
	}
	for(int i = 1;i <= n;i++){
		int minn = INF,u = 0,v = 0;
		for(int j = 1;j <= n;j++){
			if(i == j)
				continue;
			if(minn > num[j][i]){
				minn = num[j][i];
				u = j;
				v = i;
			}
		}
		ans += minn;
		if(w[u][v] != minn && vis[u] == false && vis[v] == false){
			if(u > k)
				ans += c[v][0];
			 else if(v > k)
				ans += c[u][0];
			else
				ans += min(c[u][0],c[v][0]);
			vis[u] = vis[v] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
