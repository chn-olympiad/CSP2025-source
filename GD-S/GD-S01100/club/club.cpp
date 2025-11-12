#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 2e5+10;
int t;
int n; ll a[N][4];
int s[4];
struct node { int yl; ll cha; } b[N];

bool cmp (node x1, node x2) {
	return x1.cha < x2.cha;
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		ll ans = 0;
		ll m1, m2; int cnt;
		s[1] = s[2] = s[3] = 0;
		for (int i = 1; i <= n; i++) {
			m1 = m2 = cnt = 0;
			for (int j = 1; j <= 3; j++) {
				scanf("%lld", &a[i][j]);
				if (a[i][j] >= m1) {
					m2 = m1, m1 = a[i][j];
					cnt = j;
				}
				else if (a[i][j] > m2) {
					m2 = a[i][j];
				}
			}
			ans += m1;
			b[i].yl = cnt, b[i].cha = m1-m2;
			s[cnt]++;
		}
		int da = 0;
		for (int i = 1; i <= 3; i++) {
			if (s[i] > n/2) {
				da = i;
			} 
		}
		if (!da) {
			cout << ans << endl;
			continue;
		}
		sort(b+1, b+1+n, cmp);
		for (int i = 1; i <= n; i++) {
			if (b[i].yl == da) {
				ans -= b[i].cha;
				s[da]--;
				if (s[da] <= n/2) {
					cout << ans << endl;
					break;
				}
			}
		}
	}
	return 0;
}
