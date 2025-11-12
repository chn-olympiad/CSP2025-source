#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 5010;
const long long mo = 998244353;

int n;
int a[N];
long long dp[N], ans;

void init(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

void solve(){
    for(int i = 0; i <= 5000; i++)
        dp[i] = (a[1] >= i);
    for(int i = 2; i <= n; i++){
//        cout << i - 1 << ": ";
//        for(int j = 0; j <= 20; j++){
//            cout << dp[j] << " ";
//        }
//        cout << '\n';
        if(i >= 3){
            ans = (ans + dp[a[i] + 1]) % mo;
        }
        for(int j = 5000; j >= 0; j--){
            dp[j] = (dp[j] + dp[max(0, j - a[i])]) % mo;
            if(a[i] >= j)
                dp[j] = (dp[j] + 1) % mo;
        }
    }
    cout << ans << '\n';
}

void close(){
    fclose(stdin);
    fclose(stdout);
}

int main(){
    init();
    solve();
    close();
    return 0;
}
