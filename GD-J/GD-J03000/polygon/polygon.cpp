#include <cstdio>
#include <algorithm>
#include <functional>
#include <cinttypes>

typedef int64_t i64;
#define Pi64 "%" PRIi64

constexpr i64 MOD = 998244353;
constexpr int MAXN = 1e3 + 10;

i64 L[MAXN];

i64 F[MAXN], S[MAXN], iF[MAXN], A[MAXN];

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

i64 dfs(int cur, int sec, i64 sum, i64 max);

int N;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    scanf("%d", &N);

    for(int i = 1; i <= N; ++i)
        scanf(Pi64, L + i);

    // 1 ~ 3

    if(N == 3) {
        i64 sum = L[1] + L[2] + L[3];
        i64 max =std::max({L[1], L[2], L[3]});
        printf("%d", (int)(sum > max * 2));
        return 0; 
        }

    std::sort(L+1, L+N+1);

    goto other;

//     F[0] = F[1] = S[0] = S[1] = 1;
//     for(int i = 2; i <= N; ++i)
//         F[i] = F[i - 1] * i % MOD,
//         S[i] = S[i-1] * F[i] % MOD;
    
//     i64 x, y;
//     exgcd(F[N], MOD, x, y);
//     x = (x + MOD) % MOD;

//     for(int i = 1; i <= N; ++i)
//         exgcd(F[i], MOD, x, y),
//         x = (x + MOD) % MOD,
//         iF[i] = x;

//     for(int i = 1; i <= N; ++i)
//         for(int j = 1; j <= i; ++j)
//             A[i] = (A[i] + F[i] * iF[i - j] % MOD * iF[j] * MOD + MOD) % MOD;

//     i64 ans = 0;
//     for(int p = N; p >= 1; --p) { // enum L_max;
//         for(int i = p - 1; i >= 1; --i) {
//             if(L[i] + L[i - 1] <= L[p]) break;
//             for(int j = i - 1; j >= 1; --j) {
//                 if(L[i] + L[j] <= L[p]) break;
//                 ans = (ans + A[j - 1] + 1) % MOD;
//             }
//         }
//     }
// #define asdwasd9234ras
// #ifdef asdwasd9234ras
// #define parray(name, expr) \
//     fprintf(stderr, #name"= {"); \
//     for(int i = 1; i <= N; ++i) \
//         fprintf(stderr, Pi64 ", ", (expr)); \
//     fprintf(stderr, "... }\n");
// #else
// #define parray(...) 
// #endif

//     parray(L[], L[i])
//     parray(F[], F[i])
//     parray(iF[], iF[i])
//     parray(A[], A[i])
//     parray({F * iF}[], F[i] * iF[i] % MOD)

//     printf(Pi64, ans);


    other:

    printf(Pi64, dfs(1, 0, 0, 0));
}

i64 dfs(int cur, int sec, i64 sum, i64 max) {
    if(cur > N) return 0;
    
    return (
        dfs(cur + 1, sec + 1, sum + L[cur], std::max<i64>(max, L[cur]))
        + dfs(cur + 1, sec, sum, max)
        ) % MOD + (sec >= 3 && sum > 2ll*max);
}
