// mouse_boy 2025.11 CSP
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");

const ll kMaxN = 1e5 + 5;

ll T;
ll h[5][kMaxN], tot[5], b[kMaxN], n, m, ans;

struct E {
	ll x[5], maxi, mini;
} a[kMaxN];

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
	for(fin >> T; T; T--) {
		fin >> n, tot[0] = tot[1] = tot[2] = tot[3] = tot[4] = ans = 0, m = n / 2;
		for(ll i = 1; i <= n; i++) {
			fin >> a[i].x[1] >> a[i].x[2] >> a[i].x[3];
			if(a[i].x[1] >= a[i].x[2] && a[i].x[2] >= a[i].x[3]) a[i].maxi = 1, a[i].mini = 2;
			else if(a[i].x[1] >= a[i].x[3] && a[i].x[3] >= a[i].x[2]) a[i].maxi = 1, a[i].mini = 3;
			else if(a[i].x[2] >= a[i].x[1] && a[i].x[1] >= a[i].x[3]) a[i].maxi = 2, a[i].mini = 1;
			else if(a[i].x[2] >= a[i].x[3] && a[i].x[3] >= a[i].x[1]) a[i].maxi = 2, a[i].mini = 3;
			else if(a[i].x[3] >= a[i].x[1] && a[i].x[1] >= a[i].x[2]) a[i].maxi = 3, a[i].mini = 1;
			else if(a[i].x[3] >= a[i].x[2] && a[i].x[2] >= a[i].x[1]) a[i].maxi = 3, a[i].mini = 2;
			
			h[a[i].maxi][++tot[a[i].maxi]] = i, ans += a[i].x[a[i].maxi];
		}
		for(ll k = 1; k <= 3; k++) {
			if(tot[k] > m) {
				for(ll i = 1; i <= tot[k]; i++) {
					b[i] = a[h[k][i]].x[a[h[k][i]].maxi] - a[h[k][i]].x[a[h[k][i]].mini];
				} 
				sort(b + 1, b + 1 + tot[k]);
				for(ll i = 1; i <= tot[k] - m; i++) {
					ans -= b[i];
				}
			}
		}
		fout << ans << '\n';
	}
  return 0;
}
/*

cd /home/noilinux/HN-S00235/club && ulimit -s 102400 && g++ club.cpp -o club -O2 -Wall && time ./club && size ./club && ./club && diff club.out ans.out -Bb

*/
