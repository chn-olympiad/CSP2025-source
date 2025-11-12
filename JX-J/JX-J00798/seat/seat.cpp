#include<bits/stdc++.h>
using namespace std;
int a[1005],b[15][15],a1,ai[1005],aj[1005],cnti=1,cntj=1;
bool cmp(int a, int b) {
    return a>b;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++) {
        cin >> a[i];
    }
    a1 = a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt = 0;
    for (int i = 1; i <= n*m; i++) {
        if (cnti % 2 == 1) {
            ai[i] = cnt+1;
            cnt++;
        }
        else {
            ai[i] = cnt;
            cnt--;
        }
        if (i % n == 0) cnti++;
    }
    for (int i = 1; i <= n*m; i++) {
        aj[i] = cntj;
        if (i % n == 0) cntj++;
    }
    for (int i = 1; i <= n*m; i++) {
        b[ai[i]][aj[i]] = a[i];
        if (b[ai[i]][aj[i]] == a1) {
            cout << aj[i] << " " << ai[i];
            break;
        }
    }
    return 0;
}
