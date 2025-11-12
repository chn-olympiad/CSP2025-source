#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <cinttypes>

constexpr int MAXN = 1e5 + 10;

int R[3][MAXN], siz[3];

int64_t MS[MAXN];

constexpr int SEC[] = {0, 1, 2};

std::bitset<MAXN> V;

int N;

void dfs(int64_t &ans, int cur, int64_t sum);

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--) {
        // init
        for(int const i: SEC)
            siz[i] = 0;

        // int N;
        scanf("%d", &N);
        MS[N + 1] = 0;  

        bool flag_condA = true, flag_condB = true;
        for(int i = 1; i <= N; ++i) {
            scanf("%d %d %d", R[0]+i, R[1]+i, R[2]+i);
            int si = 0;
            if(R[1][i] > R[si][i]) si = 1;
            if(R[2][i] > R[si][i]) si = 2;
            MS[i] = R[si][i];
            if(R[1][i] || R[2][i]) flag_condA = false;
            if(R[2][i]) flag_condB = false;
        }

        if(flag_condA) {
            std::sort(R[0] + 1, R[0] + N, std::greater<int>());
            int64_t ans = 0;
            for(int i = 1; i <= N / 2; ++i)
                ans += R[0][i];

            printf("%" PRIi64 "\n", ans);
            continue;
        }

        if(flag_condB) {
            int64_t ans = 0;
            for(int i = 1; i <= N; ++i)
                ans += R[0][i],
                MS[i] = R[0][i] - R[1][i];
            
            // for(int i = 1; i <= N; ++i)
            //     fprintf(stderr, "mod #%d = %" PRIi64 "\n", i, MS[i]);
            
            // fprintf(stderr, "ans0=%" PRIi64 "\n", ans);

            std::sort(MS + 1, MS + N + 1, std::less<int>());
            
            for(int i = 1; i <= N / 2; ++i)
                // fprintf(stderr, "mod #%d = %" PRIi64 "\n", i, MS[i]),
                ans -= MS[i];

            printf("%" PRIi64 "\n", ans);

            continue;
        }

        for(int i = N; i > 0; --i)
            MS[i] += MS[i + 1];

        int64_t ans = -1;

        dfs(ans, 0, 0);

        printf("%" PRIi64 "\n", ans);

    }
}

void dfs(int64_t &ans, int cur, int64_t sum) {
    if(cur > N) {
        ans = std::max(ans, sum);
        return;
    }
    if(sum + MS[cur] <= ans) return;

    int si = 0;
    if(siz[si] >= N / 2 || (R[1][cur] > R[si][cur]) && siz[1] < N / 2) si = 1;
    if(siz[si] >= N / 2 || (R[2][cur] > R[si][cur]) && siz[2] < N / 2) si = 2;

    ++siz[si],
    dfs(ans, cur+1, sum+R[si][cur]),
    --siz[si];

    for (int k = 0; k < 3; ++k)
        if(k != si && siz[k] < N / 2)
            ++siz[k],
            dfs(ans, cur + 1, sum + R[k][cur]),
            --siz[k];
}