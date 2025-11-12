#include <cstdio>
#include <algorithm>
#include <functional>
#include <cinttypes>

typedef int64_t i64;
#define Pi64 "%" PRIi64

constexpr i64 MAXN = 5e5 + 10;

struct Seg {
    int L, R;

    bool operator<(Seg const &o) const {
        if(R == o.R)
            return L > o.L;
        else
            return R < o.R;
    }
};

i64 A[MAXN], S[MAXN];
Seg seg[MAXN];
int cnt = 0;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);


    i64 N, K;
    scanf(Pi64 Pi64, &N, &K);

    for(int i = 1; i <= N; ++i)
        scanf(Pi64, A + i),
        S[i] = S[i - 1] ^ A[i];
    
    for(int i = 1; i <= N; ++i)
        for(int j = i; j <= N; ++j)
            if( (S[j] ^ S[i-1]) == K )
                seg[cnt++] = {i, j};
    
    std::sort(seg, seg+cnt);

    i64 ans = 0;
    int r = -1;
    for(int i = 0; i < cnt; ++i)
        if(seg[i].L > r)
            ++ans,
            r = seg[i].R;

    printf(Pi64, ans);
}