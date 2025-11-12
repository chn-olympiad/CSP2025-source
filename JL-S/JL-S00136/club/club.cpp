#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205;
const int M = 105;

int n;
int val[N][3];
int f[M][M][M];

void bemax(int &a, int b) {
    a = a > b ? a : b;
}

void inp() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < 3; j ++ )
            scanf("%d", &val[i][j]);
}

void work() {
    memset(f, 0, sizeof f);

    for (int i = 1; i <= n; i ++ ) {
        for (int j0 = n / 2; ~j0; j0 -- )
            for (int j1 = n / 2; ~j1; j1 -- )
                for (int j2 = n / 2; ~j2; j2 -- ) {
                    if (j0)
                        bemax(f[j0][j1][j2], f[j0 - 1][j1][j2] + val[i][0]);

                    if (j1)
                        bemax(f[j0][j1][j2], f[j0][j1 - 1][j2] + val[i][1]);

                    if (j2)
                        bemax(f[j0][j1][j2], f[j0][j1][j2 - 1] + val[i][2]);
                }
    }
    
    printf("%d\n", f[n / 2][n / 2][n / 2]);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);

    while (T -- ) {
        inp();
        work();
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}