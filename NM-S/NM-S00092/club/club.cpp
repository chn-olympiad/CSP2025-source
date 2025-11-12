#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct info {
	int a, b, c;
} m[100005];
int n;
int a[100005];
int b[100005];
int c[100005];
bool t[100005];
bool f[100005];

bool cmp(info x, info y) {
    return x.a > y.a;
}
bool cmb(info x, info y) {
    return x.b > y.b;
}

inline void mai() {
	scanf("%d", &n);
	bool bnt = false, bn = false;
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i], &b[i], &c[i]),
        bnt = b[i] == c[i] && !c[i], bn = !c[i];
    if(bnt) {
        ll ans = 0;
        sort(a + 1, a + n + 1);
        for(int i = n; i > n / 2; i++) ans += a[i];
        printf("%lld", ans);
        return;
    }
    if(bn) {
        for(int i = 1; i <= n; i++)
            m[i].a = a[i], m[i].b = b[i];
        sort(m + 1, m + n + 1, cmp);
        ll ans = 0;
        for(int i = 1; i <= n / 2; i++)
            ans += m[i].a;
        for(int i = n / 2 + 1; i <= n; i++)
            ans += m[i].b;
        ll sum = ans;
        sort(m + 1, m + n + 1, cmb);
        for(int i = 1; i <= n / 2; i++)
            ans += m[i].b;
        for(int i = n / 2 + 1; i <= n; i++)
            ans += m[i].a;
        printf("%lld", max(ans, sum));
        return;
    }
	return;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) mai();
	fclose(stdin);
	fclose(stdout);
    return 0;
}

