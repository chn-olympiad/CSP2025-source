#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
using namespace std;
const int MAX=2e5+10;
int n, m, a[MAX], rm;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &m, &n);
	for (int i=1;i<=n*m;i++) scanf("%d", &a[i]);
	rm=a[1];
	sort(a+1, a+n*m+1);
	rm=n*m-(lower_bound(a+1, a+n*m+1, rm)-a)+1;
	int tmp=(rm%m)?(rm%m):m;
	printf("%d %d", (rm+m-1)/m, ((rm+m-1)/m)&1?tmp:m-tmp+1);
	return 0;
}
