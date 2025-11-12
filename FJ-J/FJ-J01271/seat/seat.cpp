#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct contestent{
	ll points, id;
};
bool cmp(contestent a, contestent b) { 
	return a.points > b.points;
}
long long n, m;
contestent aa[101];
contestent ans[11][11];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++){
		cin >> aa[i].points;
		aa[i].id = i;
	}
	sort(aa + 1, aa + 1 + n * m, cmp);
	ll cnt = 1;
	for (ll i = 1; i <= m; i++){
		if (i % 2) for (ll j = 1; j <= n; j++) ans[j][i] = aa[cnt], cnt++;
		else for (ll j = n; j >= 1; j--) ans[j][i] = aa[cnt], cnt++;
	}
	for (ll i = 1; i <= n; i++){
		for (ll j = 1; j <= m; j++){
			if (ans[i][j].id == 1) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
} 
/*
2 2
99 100 97 98
*/
