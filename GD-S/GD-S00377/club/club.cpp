#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
using lint = long long;
const int maxn = 1e5 + 9;
const lint inf = 0x7f7f7f7f7f7f7f7f;

char buf[1<<20], *p1=buf, *p2=buf;
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))==p1?EOF:*p1++)
lint read(){
	lint rs = 0, c = 0;
	while ('9' < c || c < '0'){
		c = getc();
	} while (!('9' < c || c < '0')){
		rs = rs*10 + (c^48), c = getc();
	} return rs;
}

#define rep(i, j, k) for ((i) = (j); (i) <= (k); ++(i))

int n;
int a[maxn][4];

int pn = 0;
struct ds{
	int i;
	int j;
	lint val;
} p[maxn*3];
bitset<maxn> vsd;

// .dat???

/*
	dp[i-1][j-1][k] + a[i][1] = dp[i][j][k]
	dp[i-1][j][k-1] + a[i][2] = dp[i][j][k]
	dp[i-1][j][k] + a[i][3] = dp[i][j][k] if (i-j-k) <= n/2 -> i - n/2 <= j+k
	
	
	
	dp[i-1][j-1] + a[i][1] = dp[i][j]
	dp[i-1][j] + a[i][2] = dp[i][j] if (2*(i-j) <= n) -> (j >= i - n/2)
	
	dp[i-1][j-1] + a[i][1] = dp[i][j]
	dp[i-1][j] + a[i][2] = dp[i][j] if (2*(i-j) <= n) -> (j >= i - n/2)
*/

namespace n700case{
	lint dp[409][409];
	
	void solve(){
		int i, j, k;
		
		int len = n>>1;
		
		rep (i, 0, len){
			rep(j, 0, len){
				dp[i][j] = -inf;
			}
		}
		
		dp[0][0] = 0;
		rep (i, 1, n){
			for (j = min(i, len); j >= 0; --j){
				for (k = min(i, len); k >= 0; --k){
					if (i - j - k <= len){
						dp[j][k] += a[i][3];
					}
					if (j-1 >= 0){
						dp[j][k] = max(dp[j-1][k] + a[i][1], dp[j][k]);
					}
					if (k-1 >= 0){
						dp[j][k] = max(dp[j][k-1] + a[i][2], dp[j][k]);
					}
				}
			}
		}
		
		lint ans = 0;
		rep (i, 0, len){
			rep(j, 0, len){
				ans = max(ans, dp[i][j]);
			}
		}
		
		printf("%lld\n", ans);
	}
}

int main(){
	int i, j;

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t = read();
	while (t--){
	
		n = read(), pn = 0;
		rep (i, 1, n){
			rep (j, 1, 3){
				a[i][j] = read();
			}
		}
		
		if (n <= 700){
			n700case::solve();
			continue;
		}
		
//		cerr << "sdof\n"; 
		pn = 0;
		
		rep (i, 1, n){
			rep (j, 1, 3){
				p[++pn] = ds{i, j, a[i][j]};
			}
		}
		
		sort(p + 1, p + pn + 1, [](ds a, ds b){
			return a.val > b.val;
		});
		
		vsd.reset();
		int cnt[3] = {0};
		
		lint ans = 0;
		rep (i, 1, pn){
			if (2*(cnt[p[i].j]+1) > n) continue;
			else if (vsd[p[i].i]) continue;
//			if (t==1) cerr << p[i].i << ", " << p[i].j << ", " << p[i].val << '\n';
			ans += p[i].val, vsd[p[i].i] = 1, ++cnt[p[i].j];
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
