#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 105;

int n, m, ra, a[maxn * maxn], cnt = 1;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
        if(i == 1) ra = a[i];
        else if(a[i] > ra) cnt++;
    }
    // cerr << cnt << endl;
    int l = (cnt - 1) / n + 1;
    int h = (cnt - 1) % n + 1;
    if(!(l & 1)) h = n - h + 1;
    cout << l << ' ' << h;
    return 0;
}
