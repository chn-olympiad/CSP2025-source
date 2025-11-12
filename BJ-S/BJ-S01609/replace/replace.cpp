#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
const int N = 1010;

int n, q;
char s[N][N], t[N][N], ss[N], tt[N];
int len;

bool check (int x, int now) {
    int lenn = strlen (s[x] + 1);
    for (int i = 1; i <= len; i ++) {
        if (i < now || i >= now + lenn) {
            if (ss[i] != tt[i]) return false;
        } else {
            int k = i - now + 1;
            if (s[x][k] != ss[i]) return false;
            if (t[x][k] != tt[i]) return false;
        }
    }
    return true;
}

int main () {
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    if (n > 110 || q > 210) {
        while (n --) {
            printf("0\n");
        }
        return 0;
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%s%s", s[i] + 1, t[i] + 1);
    } 

    int ans = 0;
    while (q --) {
        ans = 0;
        scanf("%s%s", ss + 1, tt + 1);
        len = strlen (ss + 1);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j + strlen (s[i] + 1) - 1 <= len; j ++) {
                if (check (i, j)) {
                    // printf("%d %d\n", i, j);
                    ans ++;
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

/*

进食后入：
十年oi一场空，不开longlong见祖宗！
关于spfa，他死了

*/