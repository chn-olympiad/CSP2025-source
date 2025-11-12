#include <cstdio>
#include <algorithm>
#include <functional>
#include <cinttypes>

typedef int64_t i64;
#define Pi64 "%" PRIi64

constexpr int MAXN = 1e3;

i64 A[MAXN];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N * M; ++i)
        scanf(Pi64, A + i);

    const int A1 = A[1];

    std::sort(A + 1, A + N*M + 1, std::greater<i64>());
    int pos = 1;
    while(A[pos] != A1) ++pos;

    int cl = (pos + N - 1) / N;

    int rem = N * cl - pos;
    int rw;

    if(cl & 1) // odd
        rw  = N - rem ;
    else
        rw = rem + 1;

    printf("%d %d", cl, rw);
}