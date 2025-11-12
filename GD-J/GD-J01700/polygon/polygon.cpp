#include <stdio.h>
#include <algorithm>
#include <bitset>

using namespace std;

// O(n^2) 的算法, 暴力计算 
#define reg register
#define FOR(i, a, b) for (reg int i = (a); i < (b); i++)
#define REP(i, a, b) for (reg int i = (a); i <= (b); i++) 
#define rREP(i, a, b) for (reg int i = (a); i >= (b); i--)
#define rFOR(i, a, b) for (reg int i = (a); i > (b); i--)

typedef long long ll;

constexpr int MOD = 998244353; // 模数  
constexpr int MAXN = 5000 + 10;
int n, arr[MAXN];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", &arr[i]);
	
	ll ans = 0;
	FOR(i, 0, (1 << n)) {
		int sum = 0, Max = 0, cnt = 0;
		FOR(j, 0, n) if ((i >> j) & 1) {
			sum += arr[j], Max = max(Max, arr[j]);
			cnt ++;
		}  
		if (sum > Max * 2 && cnt >= 3) ans++;
	}
	printf("%lld", ans % MOD);
	return 0;
}
