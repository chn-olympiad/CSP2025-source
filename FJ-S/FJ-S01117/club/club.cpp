#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll a, b, c;
};
bool cmp1(node a, node b){
	return (a.a - max(a.b, a.c)) < (b.a - max(b.b, b.c));
}
bool cmp2(node a, node b){
	return (a.b - max(a.a, a.c)) < (b.b - max(b.a, b.c));
}
bool cmp3(node a, node b){
	return (a.c - max(a.a, a.b)) < (b.c - max(b.a, b.b));
}
node aa[100001];
ll ans = 0;
ll n;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t;
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		ll cnt1 = 0, sum = 0, cnt2 = 0, cnt3 = 0;
		for (ll i = 1; i <= n; i++){
			ll tmp, tmp2, tmp3;
			cin >> tmp >> tmp2 >> tmp3;
			aa[i].a = tmp;
			aa[i].b = tmp2;
			aa[i].c = tmp3;
			if (tmp >= tmp2 && tmp >= tmp3) cnt1++, sum += tmp;
			else if (tmp2 >= tmp && tmp2 >= tmp3) cnt2++, sum += tmp2;
			else if (tmp3 >= tmp && tmp3 >= tmp2) cnt3++, sum += tmp3;
		}
		if (cnt1 > n / 2){
			ll thing = 0;
			sort(aa + 1, aa + 1 + n, cmp1);
			for (ll i = 1; i <= n; i++) {
				if ((aa[i].a - max(aa[i].b, aa[i].c)) >= 0) {
					sum -= (aa[i].a - max(aa[i].b, aa[i].c));
					thing++;
				}
				if (thing == cnt1 - n / 2) break;
			}
			cout << sum << '\n';
		}
		else if (cnt2 > n / 2){
			sort(aa + 1, aa + 1 + n, cmp2);
			ll thing = 0;
			for (ll i = 1; i <= n; i++) {
				if ((aa[i].b - max(aa[i].a, aa[i].c)) >= 0) {
					sum -= (aa[i].b - max(aa[i].a, aa[i].c));
					thing++;
				}
				if (thing == cnt2 - n / 2) break;
			}
			cout << sum << '\n';
		}
		else if (cnt3 > n / 2){
			sort(aa + 1, aa + 1 + n, cmp3);
			ll thing = 0;
			for (ll i = 1; i <= n; i++) {
				if ((aa[i].c - max(aa[i].a, aa[i].b)) >= 0) {
					sum -= (aa[i].c - max(aa[i].a, aa[i].b));
					thing++;
				}
				if (thing == cnt3 - n / 2) break;
			}
			cout << sum << '\n';
		}
		else cout << sum << '\n';
	}
	return 0;
}
