#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 5;
ll t, n, ans, cnt1, cnt2, cnt3;
struct mem{
	ll i, j, aij;
} member[N];
bool cmp(mem x, mem y){
	return x.aij > y.aij;
}
ll a[N][4];
bool ch[N][4];
signed main (){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		memset(member, 0, sizeof(member));
		memset(a, 0, sizeof(a));
		memset(ch, 0, sizeof(ch));
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		ans = 0;
		cin >> n;
		for (ll i = 1; i <= n; i++){
			for (ll j = 1; j <= 3; j++){
				cin >> a[i][j];
				ll num = 3 * (i - 1) + j;
				member[num].i = i;
				member[num].j = j;
				member[num].aij = a[i][j];
			}
		}
		sort(member + 1, member + 3 * n + 1, cmp);
		for (ll t = 1; t <= 3 * n; t++){
			ll i = member[t].i, j = member[t].j;
			ll aij = member[t].aij;
			if (!ch[i][j]){
				if (j == 1){
					if (cnt1 == n / 2) continue;
					cnt1++;
				}
				if (j == 2){
					if (cnt2 == n / 2) continue;
					cnt2++;
				}
				if (j == 3){
					if (cnt3 == n / 2) continue;
					cnt3++;
				}
				ans += aij;
				ch[i][1] = 1;
				ch[i][2] = 1;
				ch[i][3] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

