#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2;
int n,m,a[N + 5],R,c,r,v;
bool cmp(int x,int y) {
    return x > y;
}
signed main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i ++)
        cin >> a[i];
    R = a[1];
    sort(a + 1, a + n * m + 1,cmp);
    for(int i = 1 ; i <= n * m ; i ++)
        if(a[i] == R) {
            v = i;
            break;
        }
    c = ceil(v * 1.0 / n);
    if(c % 2 == 1) {
        r = v % n;
        if(!r) r = n;
    } else {
        r = n - (v % n) + 1;
        if(r == n + 1) r = 1;
    }
    cout << c << " " << r << endl;
    return 0;
}

