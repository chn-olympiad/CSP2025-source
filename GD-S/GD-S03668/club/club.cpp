#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

/*
time:
14:32~ 
思路：
考虑背包dp
先想如果只有两个社团，因为一定要分，所以有 
那么dp[i][j]为前i人，第一个社团有j个人的最大贡献 
①i在社1中：dp[i-1][j-1]+ai1
②i在社2中: dp[i-1][j]+ai2
二者取max。，可以滚掉i。

考虑三个
dp[i][j][k]为前i人，社1有j人，社2有k人，那么社3有i-j-k人
①i在社1中：dp[i-1][j-1][k]+ai1
②i在社2中: dp[i-1][j][k-1]+ai2
③i在社3中：dp[i-1][j][k]+ai3
滚掉一维，但是空间还是大 
ans = max(dp[n][j][k] 0<=j, k<=n/2)
先验证 

等等，因为重量一样，所以性价比就是价值，可以考虑贪心 
*/

const LL MAXN = 1000/*00*/+5, MAXA = 2e4+5;
struct P{
	LL a1, a2, a3;
}a[MAXN];
LL T,  n, dp[MAXN][MAXN]; 

bool cmp1(P x, P y) {
	return (x.a1-x.a2-x.a3)>(y.a1-y.a2-y.a3);
} 

bool cmp2(P x, P y) {
	return (x.a2-x.a3)>(y.a2-y.a3);
}

bool cmp3(P x, P y) {
	return (x.a1-x.a2)>(y.a1-y.a2);
} 

int main() {	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		LL n2 = n>>1;
		LL isb = true;
		for (LL i = 1; i<=n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a3) isb = false;
		}
		if (isb) {
			sort(a+1, a+1+n, cmp1);
			LL ans = 0;
			for (LL i = 1; i<=n2; i++)
				ans+=a[i].a1;
			for (LL i = n2+1; i<=n; i++)
				ans+=a[i].a2;
			cout << ans << '\n';
			continue;
		}
		if (n <= 200) {
			memset(dp, 0, sizeof(dp));
			dp[1][0] = a[1].a1, dp[0][1] = a[1].a2, dp[0][0] = a[1].a3;
			for (LL i = 2; i<=n; i++) {
				for (LL j = min(i, n2); j>=0; j--)
					for (LL k = min(i-j, n2); k>=max(0LL, i-j-n2); k--) {
						if (i-j-k) dp[j][k] = dp[j][k] + a[i].a3;
						if (j) dp[j][k] = max(dp[j][k], dp[j-1][k]+a[i].a1);
						if (k) dp[j][k] = max(dp[j][k], dp[j][k-1]+a[i].a2);
					}
			}
			LL ans = 0;	
			for (LL j = 0; j<=n2; j++)
				for (LL k = n2-j; k<=n2; k++) {
					ans = max(ans, dp[j][k]);
				}
			cout << ans << '\n';
			continue;
		}
//		cout << endl;
		sort(a+1, a+1+n, cmp3);
		LL ans = 0, in1 = 0;
		for (LL i = 1; i <= n2; i++) {
//			cout << "i=" << i << ' ';
//			cout << (a[i].a1-a[i].a2) << endl;
			if ((a[i].a1-a[i].a2) >= 0) ans+=a[i].a1, in1++; // 进1有正收益
			else  
				break;
		}
//		cout << endl << "in1:" << in1 <<  endl;
		sort(a+1+in1, a+1+n, cmp2);
		LL stp2 = 0, in2 = 0;
		for (LL i = 1+in1; i<=1+in1+n2-1; i++) {
//			cout << "i=" << i << " a:" << a[i].a1 << " " << a[i].a2 << " " << a[i].a3 << endl;
//			cout << n-in1-in2 << endl;
//			cout <<  (a[i].a2-a[i].a3) << ' ';
			if (n-in1-in2 > n2 || (a[i].a2-a[i].a3) >= 0) {
				ans += a[i].a2;
				in2++;
			}
			else {
				stp2 = i;
				break;
			}
		}
//		cout << endl;
//		cout << "stp2:" << stp2 << endl;
		for (LL i = stp2; i<=n; i++) {
//			cout << "a:" << a[i].a1 << " " << a[i].a2 << " " << a[i].a3 << endl;
			ans += a[i].a3;
		}
		cout << ans << '\n';
	}
	return 0;
}
