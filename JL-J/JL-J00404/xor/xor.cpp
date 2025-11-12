#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n, k;
int a[500005], b[500005];
int ans;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
    }
    for (int i = 1;i <= n;i ++){
        for (int j = i;j <= n;j ++){
            if ((b[i - 1] ^ b[j]) == k && i != j || a[j] == k && j == i){
                ans ++;
                i += j - i;
                if (i != j) i --;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
