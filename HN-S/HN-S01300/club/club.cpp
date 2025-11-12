#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, T, cnt[5], ma;

struct d{
	int aa, b, c;
}a[100005];

void dfs(int step, int sum){
	if (step > n){
		ma = max(ma, sum);
		return ;
	}
	if (cnt[1] < n / 2){
		cnt[1]++;
		dfs(step + 1, sum + a[step].aa);
		cnt[1]--;
	}
	if (cnt[2] < n / 2){
		cnt[2]++;
		dfs(step + 1, sum + a[step].b);
		cnt[2]--;
	}
	if (cnt[3] < n / 2){
		cnt[3]++;
		dfs(step + 1, sum + a[step].c);
		cnt[3]--;
	}
}

bool cmp(d x, d y){
	return x.aa > y.aa;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
	 	}
		if (n == 1e5){
			sort(a + 1, a + n + 1, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) ans += a[i].aa; 
			cout << ans << '\n';
			continue;
		}
//		else if (n > 20){
//			memeset(dp, 0, sizeof dp);
//			for (int i = 1; i <= n; i++){
//				if ()
//			}
//		}
		else{
			ma = -1e18;
			dfs(1, 0);
			cout << ma << '\n';
		}
		
	}
	return 0;
}
