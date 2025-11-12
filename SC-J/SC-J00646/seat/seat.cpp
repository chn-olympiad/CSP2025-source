#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 15;
struct Node {
    int id, val;
} s[N * N];
int cnt;
bool cmp(Node a, Node b) { return a.val > b.val; }
int pl;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            scanf("%d", &s[++cnt].val);
            s[cnt].id = cnt;
        }
    sort(s + 1, s + cnt + 1, cmp);
    // for(int i = 1; i <= cnt; i++)
    //     printf("%d %d\n", s[i].val, s[i].id);
    for(int i = 1; i <= cnt; i++)
        if(s[i].id == 1) pl = i;
    // printf("pl : %d\n", pl);
    int x = 1, y = 1;
    while(1) {
        pl--;
        if(!pl) {
            printf("%d %d\n", x, y);
            return 0;
        }
        // printf("xx %d %d\n", x, y);
        if(x & 1) y = y + 1;
        else y = y - 1;
        if(y > m) y = m, x = x + 1;
        else if(y < 1) y = 1, x = x + 1;
        if(x == m && y == n && (m & 1)) break;
        if(x == m && y == 1 && !(m & 1)) break;
    }
    return 0;
}