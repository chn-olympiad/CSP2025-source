#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
ll n, m;
ll r;
ll s[105];
bool vis[15][15];
bool flag = false;
ll dx[] = {0, -1, 1, 0};
ll dy[] = {0, 0, 0, 1};
void dfs(ll x, ll y, ll a){
	if(flag) return;
	if(s[a] == r){
		flag = true;
		cout << y << " " << x << endl;
		return;
	}
	for(int i = 1; i <= 3; i ++){
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
		if(vis[nx][ny]) continue;
		vis[nx][ny] = true;
		dfs(nx, ny, a + 1);
	}
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++){
		cin >> s[i];
	}
	memset(vis, false, sizeof vis);
	r = s[1];
	sort(s + 1, s + n * m + 1, greater<int>());
	vis[1][1] = true;
	dfs(1, 1, 1);
	return 0;
}