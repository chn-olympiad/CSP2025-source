#include <bits/stdc++.h>
using namespace std;

inline int fxor(int a, int b){
    int c = (a & ~b) | (~a & b);
    return c;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    int n;
    cin >> n >> k;
    int a[n] = {};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (k == 0) cout << n / 2;
    else if (k == 1){
        int cnt = 0;
        for (int i = 0;i < n; i++){
            if ((a[i] == 1 && a[i - 1] == 0) || (a[i] == 0 || a[i - 1] == 1)) cnt++;
        }
        cout << cnt;
    }
    return 0;
}
