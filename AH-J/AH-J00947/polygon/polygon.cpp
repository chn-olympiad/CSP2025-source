#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n[114514], a;
    cin >> a;
    cin >> n[1] >> n[2] >> n[3];
    sort(n+1, n+4);
    if (n[3]<n[1]+n[2]) cout << 1;
    else cout << 0;
    return 0;
}
