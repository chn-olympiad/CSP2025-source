#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int stick[5007];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> stick[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            for (int k = j + 1; k <= n; k++){
                if (i == j || i == k || j == k){
                    continue;
                }
                long long sum = stick[i] + stick[j] + stick[k];
                int maxx = max(stick[i], max(stick[j], stick[k]));
                if (sum > maxx * 2){
                    ans++;
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
