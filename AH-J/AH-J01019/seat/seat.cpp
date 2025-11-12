#include<bits/stdc++.h>
using namespace std;
int n, m, s, si;
int a[105];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n*m; i++) {
        cin >> a[i];
    }
    s = a[1];
    sort(a+1, a+n*m+1, greater<int>());
    for (int i=1; i<=n*m; i++) {
        if (a[i] == s) {
            si = i;
        }
    }
    int c = si/n, r = si%n;
    if (r != 0) {
        c ++;
    }else{
        r = n;
    }
    if (c %2 == 0) {
        r = n-r+1;
    }
    cout << c << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//%%%%%
//orz orz orz
