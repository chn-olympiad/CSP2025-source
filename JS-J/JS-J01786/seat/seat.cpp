#include <bits/stdc++.h>
using namespace std;


bool cmp(const int a, const int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, self = 0;
    cin >> n >> m;
    int a[n * m] = {};
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    self = a[1];

    sort(a + 1, a + n * m + 1, cmp);

    int x = 0, y = 0, pos = 0;
    for (int i = 0; i <= n * m; i++){
        if (a[i] == self){
            pos = i;
            break;
        }
    }
    cout << (pos - 1) / n + 1 << " ";
    if (((pos - 1) / n + 1) % 2 == 0){
        cout << n + 1 - ((pos - 1) % n + 1);
    }else {
        cout << (pos - 1) % n + 1;
    }

    return 0;
}
