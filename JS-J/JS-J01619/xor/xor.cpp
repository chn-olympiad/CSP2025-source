#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k;
    int a[500005] = {0};

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r_last, xor_n, cnt = 0;
    while (true){
        int xor_n = 0;
        for (int r = l; r <= n; r++){
            xor_n = xor_n ^ a[r];
            if (xor_n == k){
                r_last = r;
                break;
            }
        }
        if (xor_n == k){
            cnt++;
            l = r_last + 1;
        }
        else {
            l += 1;
        }
        if (l > n) break;
    }

    cout << cnt;

    return 0;
}
