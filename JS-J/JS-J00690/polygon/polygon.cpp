#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3;
const int MOD = 998244353;
int n;
long long ans;
int a[N + 5];
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n - 2; i ++){
        for(int j = i + 1; j <= n - 1; j ++){
            for(int k = j + 1; k <= n; k ++){
                if(a[i] + a[j] > a[k]){
                    ans ++;
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}