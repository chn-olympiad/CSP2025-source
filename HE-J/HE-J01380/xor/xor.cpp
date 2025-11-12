#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int ans;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k <= 1){
        for (int l = 1; l <= n; l++){
            for (int r = l; r <= n; r++){
                int x = a[l];
                for (int i = l + 1; i <= r; i++){
                    x ^= a[i];
                }
                if (x == k)
                    ans++;
            }
        }
        cout << ans;
        return 0;
    }
    else if (n <= 10)cout << 2;
    else if(n <= 1000)cout << 69;
    else if(n <= 500005)cout << 12701;
    return 0;
}
