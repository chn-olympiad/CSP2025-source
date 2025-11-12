#include <bits/stdc++.h>

#define LL long long
using namespace std;
const int N = 3000 + 10;

struct node{
	int x, t;
	bool operator < (const node &y) const{
		return (x > y.x);
	}
}a[N][3];
LL ans;
int cnt[3], n;

void dfs(int p, LL s, int lst){
	if(cnt[lst] > n / 2) return ;
	if(p == n + 1){
		ans = max(ans, s);
		return ;
	}
	sort(a[p], a[p] + 3);
	for(int i = 0;i < 3;i ++){
		int x = a[p][i].x, t = a[p][i].t;
		cnt[t]++;
		dfs(p + 1, s + x, t);
		cnt[t]--;
	}
}

void solve(){
	ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i][0].x >> a[i][1].x >> a[i][2].x,
		a[i][0].t = 0, a[i][1].t = 1, a[i][2].t = 2;
	if(n > 200){
		for(int i = 1;i <= n;i ++)
			sort(a[i], a[i] + 3);
		for(int i = 1;i <= n;i ++)
			ans += a[i][0].x;
	}
	else dfs(1, 0, 0);
	for(int i = 0;i < 3;i ++)
		cnt[i] = 0;
	cout << ans << "\n";
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}

