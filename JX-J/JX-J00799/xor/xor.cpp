#include<bits/stdc++.h>
using namespace std;
int n, k, now, a[500005], ans, last, s[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = (s[i-1]^a[i]);
        if (a[i] == k){
            ans ++;
            now = 0;
            last = i;
        }
        else {
            now ^= a[i];
            if (now == k){
                last = i;
                now = 0;
                ans ++;
                continue;
            }
            if (k != 0 && k != 1){
                int t = now;
                for (int j = last + 1; j < i; j ++){
                    int l = ((s[j]^s[last])^t);
                    if (l == k){
                        last = i;
                        now = 0;
                        ans ++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}
