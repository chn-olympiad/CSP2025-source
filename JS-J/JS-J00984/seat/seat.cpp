#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int a[N];

int main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int My = 0;

    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    My = a[1];
    sort(a + 1, a + 1 + n * m);
    int cnt = 0;
    for(int i = 1; i <= n * m; i++){
        if(My == a[i]){
            cnt = i;
            break;
        }
    }
    cnt = n * m - cnt + 1;
    int k = (cnt - 1) / n + 1, l = cnt % n;
    if(l == 0) l = n;
    if(k % 2 == 0) l = n - l + 1;
    cout << k << " " << l << endl;

    
    return 0;
}