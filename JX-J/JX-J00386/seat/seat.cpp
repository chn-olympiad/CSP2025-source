#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int res = 0;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++) {
        cin >> a[i];
    }
    int t = a[1];
    sort(a + 1,a + n * m + 1);
    for(int i = 1;i <= n * m;i++) {
        if(t <= a[i])res++;
    }
    int x, y;
    if(res % n == 0) {
        y = res / n;
        x = n;
    }
    else {
        y = res / n + 1;
        x = res % n;
    }
    if(y % 2 == 0) {
        x = n - x + 1;
    }
    cout << y << ' ' << x << '\n';
    return 0;
}
