#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long a[N];
int n, k, ans = 0;

void dfs(int beg, int num) {
    for (int j = beg; j <= n; j++) {
        long long temp = 0;
		bool flag = false;
        for (int i = j; i <= n; i++) {
            temp ^= a[i];
            if (temp == k) {
                flag = true;
                dfs(i + 1, num + 1);
                break;
            }
        }
		ans = max(ans, num + flag);
    }
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
    dfs(1, 0);
    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
