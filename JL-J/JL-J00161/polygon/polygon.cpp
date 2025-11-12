#include <cstdio>
#include <vector>
using namespace std;

const int N = 5e3 + 5;
const int mod = 998244353;

int n;
int len[N];
int ans;

void bemax(int &a, int b) {
    a = a > b ? a : b;
}

void inp() {
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ )
        scanf("%d", &len[i]);
}

void work() {
    for (__int128 k = 0; k < (__int128)1 << n; k ++ ) {
        int sum = 0, maxl = 0;

        for (int i = 0; i < n; i ++ )
            if (k >> i & 1) {
                sum += len[i];
                bemax(maxl, len[i]);
            }
        
        if (sum > 2 * maxl)
            ans = (ans + 1) % mod;
    }

    printf("%d\n", ans);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}