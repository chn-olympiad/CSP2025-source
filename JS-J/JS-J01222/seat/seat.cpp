#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m; cin >> n >> m;

    int a; cin >> a;
    int cnt(0);

    int tmp = n * m;
    for(int i = 2; i <= tmp; i++ ){
        int x; cin >> x;
        cnt += (x > a);
    }

    int c = cnt / n + 1;
    cout << c << ' ';

    int r = cnt % n + 1;
    if(c & 1) cout << r;
    else cout << n - r + 1;

    return 0;

}
