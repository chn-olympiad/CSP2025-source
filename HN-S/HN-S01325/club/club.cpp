#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int T, n, a[N][5], ans, cnt[5], c[N];
struct node{
	int s, id, id2;
}b[N], k[5];

bool cmp(node p, node q){
	return p.s > q.s;
}

bool cmp1(node p, node q){
	return p.s > q.s;
}

void dfs(int d, int t){
	if(d == n + 1){
		ans = max(ans, t);
		return ;
	}
	for(int i = 1; i <= 3; i++){
		if(cnt[i] < n / 2){
			cnt[i]++;
			dfs(d + 1, t + a[d][i]);
			cnt[i]--;
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> a[i][j];
		}
	}
	ans = 0;
	if(n <= 10){
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		dfs(1, 0);
		cout << ans << "\n";
	}else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				k[j].s = a[i][j];
				k[j].id = j;
			}
			sort(k + 1, k + 3 + 1, cmp);
			b[i].s = k[1].s;
			b[i].id = k[1].id;
			b[i].id2 = i;
			c[i] = k[2].s;
		}
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		sort(b + 1, b + n + 1, cmp1);
		ans = 0;
		for(int i = 1; i <= n; i++){
			if(cnt[b[i].id] < n / 2){
				ans += b[i].s;
				cnt[b[i].id]++;
			}else{
				ans += c[b[i].id2];
			}
		}
		cout << ans << "\n";
	}	
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
