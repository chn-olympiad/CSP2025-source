#include <cstdio>
#include <cstdlib>

#include <vector>
#include <tuple>
#include <algorithm>
#include <cinttypes>

typedef int64_t i64;
#define Pi64 "%" PRIi64

constexpr int MAXN = 5e2 + 10;

constexpr i64 MOD = 998244353;

i64 F[MAXN], S[MAXN], iF[MAXN];

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * d;
    return d;
}

void prepare(int N) {
    F[0] = F[1] = S[0] = S[1] = 1;
    for(int i = 2; i <= N; ++i)
        F[i] = F[i-1] * i % MOD,
        S[i] = S[i-1] * F[i] % MOD;

    i64 x, y;
    exgcd(S[N], MOD, x, y);
    x = (x + MOD) % MOD;

    for(int i = N; i > 0; --i)
        iF[i] = S[i-1] * x % MOD,
        x = x * F[i] % MOD;
    iF[0] = 1;
}

int N, M;

char P[MAXN];

int C[MAXN], X[MAXN];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    
    scanf("%d %d", &N, &M);
    scanf("%s", P);

    int x = 0;
    for(int i = 1; i <= N; ++i)
        scanf("%d", C+i),
        x += C[i] == 0,
        X[i] = X[i-1] + (P[i] == '0');

    prepare(N);

    std::sort(C + 1, C + N + 1);

    // solve for pt12 ~ 14
    if(M == 1) {
        int pos = 1;
        while(P[pos] == '0') ++pos;

        int gpos = std::upper_bound(C + 1, C + N + 1, X[pos]) - C;

        i64 ans = F[N - 1] * (N - gpos + 1) % MOD;

        printf(Pi64, ans);
    }
}