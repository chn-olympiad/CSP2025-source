#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N][4];
int n, len;
int home[4];
int ans = -0x3f3f3f3f;
int path[N];
void dfs(int dep, int sum){
	if(dep == n){
		ans = max(ans, sum);
		return ;
	}
	
	if(home[1] < n / 2){
		home[1]++;
		sum += a[dep+1][1];
		dfs(dep+1, sum);
		sum -= a[dep+1][1];
		home[1]--;
	}
	
	if(home[2] < n / 2){
		home[2]++;
		sum += a[dep+1][2];
		dfs(dep+1, sum);
		sum -= a[dep+1][2];
		home[2]--;
	}
	
	if(home[3] < n / 2){
		home[3]++;
		sum += a[dep+1][3];
		dfs(dep+1, sum);
		sum -= a[dep+1][3];
		home[3]--;
	}
}

int A[N];
void checkA(){
	int ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		A[i] = a[i][1];
	}
	sort(A+1, A+1+n);
	for(int i = n; i >= 1; i--){
		ans+=A[i];
		cnt++;
		if(cnt >= n/2){
			cout << ans << '\n';
			return ;
		}
	}
}

void solve(){
	ans = 0;
	len = 0;
	memset(a, 0, sizeof a);
	memset(home, 0, sizeof home);
	cin >> n;
	
	int aa = 0, bb = 0, cc = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> a[i][j];
		}
		if(a[i][1] == 0){
			aa++;
		}else if(a[i][2] == 0){
			bb++;
		}else if(a[i][3] == 0){
			cc++;
		}
	}
	if(bb == n && cc == n){
		checkA();
		return ;
	}
	dfs(0, 0);
	cout << ans << '\n';
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
