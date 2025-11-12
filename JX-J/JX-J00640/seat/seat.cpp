#include <bits/stdc++.h>

using namespace std;

int n , m, a[100001], d = 0;
int b[1001][1001];

int main() {
    scanf("%d%d", &n, &m);
    int q = n * m;
    for (int i = 1; i <= q; i++)
        scanf("%d", a[i]);
    int d = a[1];
    int x = q + 1;
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 1; j--){
            --x;
            b[i][j] = a[x];
        }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] == d){
                printf("%d %d\n", i, j);
                return 0;
            }
}


