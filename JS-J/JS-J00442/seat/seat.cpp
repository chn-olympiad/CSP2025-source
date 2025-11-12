#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], id = 1, num[105][105];
int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    n = read(); m = read();
    for(int i = 1; i <= n * m; i++) a[i] = read();
    int x = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    for(int i = 1; i <= m; i++) {
        if(i % 2 == 1) {
            for(int j = 1; j <= n; j++) 
                num[j][i] = a[id++];
        }
        else {
            for(int j = n; j >= 1; j--) 
                num[j][i] = a[id++];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(num[i][j] == x) {
                printf("%d %d\n", j, i);
                return 0;
            }
        }
    }
    return 0;
}