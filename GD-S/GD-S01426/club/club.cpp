#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll T, n, a[N][3], ch[N], f[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		ll ans = 0, cnt[3] = {0};
		for(int i = 1; i <= n; i++){
			ll mx = 0;
			for(int j: {0, 1, 2}) cin >> a[i][j], mx = max(mx, a[i][j]);
			for(int j: {0, 1, 2}) if(a[i][j] == mx){ ans += a[i][j]; ch[i] = j; break;}
			cnt[ch[i]]++;
		}
		for(int i: {0, 1, 2}) if(cnt[i] > n / 2){
			ll ct = 0;
			for(int j = 1; j <= n; j++) if(ch[j] == i){
				ll mx = 0;
				for(int k: {0, 1, 2}) if(k != i) mx = max(mx, a[j][k]);
				f[++ct] = a[j][i] - mx;
			}
			sort(f + 1, f + ct + 1);
			for(int j = 1; j <= cnt[i] - n / 2; j++) ans -= f[j];
		}
		cout << ans << '\n';
	}
	return 0;
} 
