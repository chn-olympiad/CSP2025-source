#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
bool cmp(int a, int b) {
    return a>b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for (int i=1; i<=n*m; i++) {
        cin>>a[i];
    }
    int R=a[1], idx;
    sort(a+1, a+n*m+1, cmp);
    for (int i=1; i<=n*m; i++) {
        if (a[i]==R) {
            idx=i;
            break;
        }
    }
    if (idx%n==0) {
        int lie=idx/n;
        if (lie%2==0) {
            printf("%d %d", lie, 1);
        } else {
            printf("%d %d", lie, n);
        }
    } else {
        int lie=idx/n+1;
        if (lie%2==0) {
            int cnt=idx%n;
            printf("%d %d", lie, n-cnt+1);
        } else {
            int cnt=idx%n;
            printf("%d %d", lie, cnt);
        }
    }
    return 0;
}
