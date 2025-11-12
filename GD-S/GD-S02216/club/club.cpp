#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int T, n, m, a[N][4], sum[4];
ll ans;
bool vis[N];

void DFS(int x, ll s){
	if(x > n){
		ans = max(s, ans);
		return;
	}
	for(int c = 1; c <= 3; ++c){
		if(sum[c] >= m) continue;
		vis[x] = 1;
		++sum[c];
		DFS(x + 1, s + a[x][c]);
		vis[x] = 0;
		--sum[c];
	}
}

void solve(){
	cin >> n;
	m = (n >> 1);
	bool all0 = true;
	for(int i = 1; i <= n; ++i){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2] != 0 || a[i][3] != 0) all0 = false;
	}
	if(!all0) DFS(1, 0), cout << ans << "\n";
	else{
		priority_queue<int> q;
		for(int i = 1; i <= n; ++i) q.push(a[i][1]);
		while((m--) && !q.empty()){
			ans += q.top();
			q.pop();
		}
		cout << ans << "\n";
	}
	ans = 0;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--) solve();
	return 0;
}
