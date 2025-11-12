#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[105], r, f, h, l, e;
bool cmp(int a, int b){
    return a > b;
}
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i){
        cin >> a[i];
        if (i == 1) r = a[1];
    }
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = n * m; i >= 1; --i){
        if (a[i] == r) {
            f = i;
        }
    }
    if (f % n > 0) l = f / n + 1;
    else l = f / n;
    if (f % n > 0) e = f % n;
    else e = n;
    if (l % 2 == 1) h = e;
    else h = n - e + 1;
    cout << l << ' ' << h;
    return 0;
}
