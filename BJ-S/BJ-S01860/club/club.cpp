

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int N;
int res;
vector<int> cg[3];

int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int a, b, c;
    int mx;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < 3; i++) cg[i].clear();
        res = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d%d", &a, &b, &c);
            mx = max(a, max(b, c)), res += mx;
            if (mx == a) cg[0].push_back(mx - max(b, c));
            else if (mx == b) cg[1].push_back(mx - max(a, c));
            else cg[2].push_back(mx - max(a, b));
        }
        for (int i = 0; i < 3; i++) {
            sort(cg[i].begin(), cg[i].end());
            if (cg[i].size() > N / 2)
                for (int j = 0; j < cg[i].size() - N / 2; j++) res -= cg[i][j];
        }
        printf("%d\n", res);
    }
    return 0;
}