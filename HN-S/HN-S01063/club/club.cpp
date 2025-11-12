#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 100;
int t, n;
struct node{
	int a1, a2, a3, tp, opt1, opt2, opt3;
} a[N];
bool cmp1(node i, node j){
	return i.opt1 > j.opt1;
}
bool cmp2(node i, node j){
	return i.opt2 > j.opt2;
}
bool cmp3(node i, node j){
	return i.opt3 > j.opt3;
}
bool cmp4(node i, node j){
	return i.tp < j.tp;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --){
		cin >> n;
		for (int i = 1; i <= n; i ++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			int ma, mi, mid;
			ma = max(a[i].a1, max(a[i].a2, a[i].a3)), mi = min(a[i].a1, min(a[i].a2, a[i].a3));
			mid = mi;
			if (a[i].a1 != ma && a[i].a1 != mi) mid = a[i].a1;
			if (a[i].a2 != ma && a[i].a2 != mi) mid = a[i].a2;
			if (a[i].a3 != ma && a[i].a3 != mi) mid = a[i].a3;
			if (ma == a[i].a1) a[i].opt1 = 1, a[i].opt2 = 0, a[i].opt3 = 0;
			if (ma == a[i].a2) a[i].opt1 = 0, a[i].opt2 = 1, a[i].opt3 = 0;
			if (ma == a[i].a3) a[i].opt1 = 0, a[i].opt2 = 0, a[i].opt3 = 1;
			a[i].tp = ma - mid;
		}
		int cnt1 = 0, sum = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i ++){
			int ma = max(a[i].a1, max(a[i].a2, a[i].a3));
			if (ma == a[i].a1) cnt1 ++;
			else if (ma == a[i].a2) cnt2 ++;
			else if (ma == a[i].a3) cnt3 ++;
			sum += ma;
		}
		if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2){
			cout << sum << "\n";
			continue;
		}
		
		if (cnt1 > n / 2){
			sort(a + 1, a + 1 + n, cmp1);
			sort(a + 1, a + 1 + cnt1, cmp4);
			for (int i = 1; i <= cnt1 - n / 2; i ++){
				sum -= a[i].tp;
			}
			cout << sum << "\n";
		}
		else if (cnt2 > n / 2){
			sort(a + 1, a + 1 + n, cmp2);
			sort(a + 1, a + 1 + cnt2, cmp4);
			for (int i = 1; i <= cnt2 - n / 2; i ++){
				sum -= a[i].tp;
			}
			cout << sum << "\n";
		}
		else if (cnt3 > n / 2){
			sort(a + 1, a + 1 + n, cmp3);
			sort(a + 1, a + 1 + cnt3, cmp4);
			for (int i = 1; i <= cnt3 - n / 2; i ++){
				sum -= a[i].tp;
			}
			cout << sum << "\n";
		}
	}
	return 0;
}
