#include <bits/stdc++.h>
#define ll long long
const int N = 1e5 + 5;
using namespace std;
ll T;
ll zzz[N];
ll aa[N], bb[N], cc[N];
struct m {
	ll a;
	ll b;
	ll c;
	bool flag = false;
};
m L[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);


	while (T--) {
		ll ans = 0;
		ll maxn = -1e9;
		ll n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &L[i].a, &L[i].b, &L[i].c);
		}
		ll lasti = 0, lastj = 0, lastk = 0;
		ll x = 0, y = 0,  z = 0;
		if (n <= 2) {
			for (int i = 1; i <= 2; i++) {
				for (int j = 1; j <= 2; j++) {
					for (int j = 1; j <= 2; j++) {
						maxn = L[1].a + L[2].b;
						maxn = max(maxn, L[1].a + L[2].c);
						maxn = max(maxn, L[1].b + L[2].a);
						maxn = max(maxn, L[1].b + L[2].c);
						maxn = max(maxn, L[1].c + L[2].a);
						maxn = max(maxn, L[1].c + L[2].b);
					}
				}
			}
			cout << maxn << endl;

		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {

					for (int k = 1; k <= n; k++) {
						if (i == j || i == k || j == k) continue;
						//if (L[i].flag == true || L[j].flag == true || L[k].flag == true) continue;
						int ans = L[i].a + L[j].b + L[k].c;
						if (ans > maxn) {
							maxn = ans;
							L[i].flag = true;
							L[j].flag = true;
							L[k].flag = true;
							x = i, y = j, z = k;
							L[lasti].flag = false;
							L[lastj].flag = false;
							L[lastk].flag = false;
							lasti = i;
							lastj = j;
							lastk = k;
						}

					}
				}
			}
			ll cnt = maxn;
			L[x].a = 0;
			L[y].b = 0;
			L[z].c = 0;
			ll cnta = 1, cntb = 1, cntc = 1;
			maxn = 0;
			
			for (int i = 1; i <= n; i++) {
				aa[i] = L[i].a;
				bb[i] = L[i].b;
				cc[i] = L[i].c;
			}
			int tar = n - 3;
			while (tar--){
				for (int i = 1; i <= n; i++){
					if (cnta <= n / 2){
						maxn = max(aa[i], maxn);
					}
					if (cntb <= n / 2){
						maxn = max(bb[i], maxn);
					}
					if (cntc <= n / 2){
						maxn = max(cc[i], maxn);
					}
				
				}
				//cout << maxn << endl;
				cnt += maxn;
				for (int i = 1; i <= n; i++){
					if (maxn == aa[i]){
						cnta++;
						aa[i] = 0;
					}
					else if (maxn == bb[i]){
						cntb++;
						bb[i] = 0;
					}
					else if (maxn == cc[i]){
						cntc++;
						cc[i] = 0;
					}
				}
				maxn = 0;
			}

			
			cout << cnt << endl;
		}

	}

	return 0;
}


