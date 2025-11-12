#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 5;
struct club {
    int x, id;
}b[N];
int cmp(club x, club y) {
    return x.x > y.x;
}
int n;
int a[N][P];
int tot[P];
int id_p[P][N];
int c[N], del[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        long long ans = 0;
        //printf("b: \n");
        for (int i = 1; i <= n; i++) {
            club s[P];
            for (int j = 0; j < 3; j++) {
                scanf("%d", &a[i][j]);
                s[j].x = a[i][j];
                s[j].id = j;
            }
            sort(s, s + 3, cmp);
            b[i] = s[0];
            ans += b[i].x;
            //printf("%d\n", b[i].x);
        }
        //printf("%d\n", ans);
        int mxn = n / 2;
        vector<int> peo(P, 0);
        int f = -1;
        //printf("solve: \n");
        for (int i = 1; i <= n; i++) {
            //printf("%d\n", b[i].id);
            peo[b[i].id]++;
            id_p[b[i].id][++tot[b[i].id]] = i;
            if (peo[b[i].id] > mxn) {
                f = b[i].id;
            }
        }
        //printf("f: %d\n", f);
        if (f != -1) {
            //printf("c: \n");
            for (int i = 1; i <= tot[f]; i++) {
                for (int j = 0; j < 3; j++) {
                    if (j != b[id_p[f][i]].id) {
                        c[i] = max(c[i], a[id_p[f][i]][j]);
                    }
                }
                //printf("%d    ", i);
                //printf("%d: ", c[i]);
                del[i] = b[id_p[f][i]].x - c[i];
                //printf("%d %d\n", b[id_p[f][i]].x, c[i]);
                //printf("del %d\n", del[i]);
            }
            sort(del + 1, del + tot[f] + 1);
            /*for (int i = 1; i <= tot[f]; i++) {
                printf("%d\n", del[i]);
            }*/
            for (int i = 1; i <= tot[f] - mxn; i++) {
                ans -= del[i];
            }
        }
        printf("%d\n", ans);
        memset(c, 0, sizeof(c));
        memset(tot, 0, sizeof(tot));
    }
    return 0;
}
