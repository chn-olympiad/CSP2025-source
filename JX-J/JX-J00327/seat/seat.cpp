#include <bits/stdc++.h>
using namespace std;
int c[105];
bool cmp (int a,int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n*m;++i) cin >> c[i];
    int k = c[1];
    sort(c+1,c+1+n*m,cmp);
    int i=1,j=1;
    for (int o=1;o<=n*m;++o) {
        if (c[o] == k) {
            cout << j << ' ' << i;
            break;
        }
        if (i == n && j & 1 || i == 1 && !(j & 1)) ++j;
        else if (j & 1) ++i;
        else --i;
    }
    return 0;
}
