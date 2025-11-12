#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
ll a1[100010], a2[100010], a3[100010];
ll b1[100010], b2[100010], b3[100010];
int cnt1, cnt2, cnt3;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t --){
		cnt1 = cnt2 = cnt3 = 0;
		cin >> n;
		ll ans = 0;
		for(int i = 1; i <= n; i ++){
			cin >> a1[i] >> a2[i] >> a3[i];
			ll maxn = max(a1[i], max(a2[i], a3[i]));
			if(maxn == a1[i]){
				ans += a1[i];
				b1[++cnt1] = min(a1[i] - a2[i], a1[i] - a3[i]);
			}
			else if(maxn == a2[i]){
				ans += a2[i];
				b2[++cnt2] = min(a2[i] - a1[i], a2[i] - a3[i]);
			} else{
				ans += a3[i];
				b3[++cnt3] = min(a3[i] - a1[i], a3[i] - a2[i]);
			}
		}
		sort(b1 + 1, b1 + cnt1 + 1, greater <ll>());
		sort(b2 + 1, b2 + cnt2 + 1, greater <ll>());
		sort(b3 + 1, b3 + cnt3 + 1, greater <ll>());
		while(cnt1 > n / 2) ans -= b1[cnt1 --];
		while(cnt2 > n / 2) ans -= b2[cnt2 --];
		while(cnt3 > n / 2) ans -= b3[cnt3 --];
		cout << ans << '\n';
	}
	return 0;
}
