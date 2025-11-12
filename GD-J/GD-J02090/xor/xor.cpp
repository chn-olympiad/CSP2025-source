#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
using namespace std;
const int MAX=5e5+10, MAXM=2e6+10;
int n, k, a[MAX], sum[MAX], pos[MAXM], now=-1, ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	fill(pos+1, pos+2000001, -1);
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		sum[i]=sum[i-1]^a[i];
		if (pos[sum[i]^k]>now) {
			ans++;
			now=i;
		}
		pos[sum[i]]=i+1;
	}
	printf("%d", ans);
	return 0;
}
