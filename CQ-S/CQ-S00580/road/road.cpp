#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 10010;
int n,m,k,p[20],b[20][MAXN],ans;
bool vis[MAXN];
struct cunc{
	int x,y,z;
}a[MAXN * 100];
void dfs(int x){
	vis[x] = 1;
	int flag = 1;
	for(int i = 1; i <= n; i++){
		if(!vis[i]) flag = 0;
	}
	if(flag) return;
	int id,mn = INT_MAX,wx = 0;
	for(int i = 1; i <= m; i++){
		if(a[i].x == x && !vis[a[i].y]){
			if(mn > a[i].z){
				id = a[i].y;
				mn = a[i].z;
			}
		}
		if(a[i].y == x && !vis[a[i].x]){
			if(mn > a[i].z){
				id = a[i].x;
				mn = a[i].z;
			}
		}
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			if(p[i] + b[i][x] + b[i][j] < mn && j != x && !vis[j]){
				mn = p[i] + b[i][x] + b[i][j];
				wx = i;
				id = j;
			}
		}
	}
	ans += mn;
	p[wx] = 0;
	dfs(id);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	for(int i = 1; i <= k; i++){
		cin >> p[i];
		for(int j = 1; j <= n; j++){
			cin >> b[i][j];
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
