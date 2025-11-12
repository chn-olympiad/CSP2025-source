#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n;
int a[5005];
long long d[5005];
long long ans;

void solve(int id,int max_n,int sum){
    if (sum + d[id + 1] < max_n) return;
    if (sum > 2 * max_n) ans++,ans %= MOD;
    if (id == n) return;
    for (int i = id + 1;i <= n;i++){
        solve(i,max(max_n,a[i]),sum + a[i]);
    }
}

long long C(int n,int m){
    long long ans = 1;
    for (int i = 1;i <= m;i++){
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = n;i >= 1;i--){
        d[i] = d[i + 1] + a[i];
    }
    if (n <= 20){
        solve(0,0,0);
        cout << ans;
    }
    else if (n > 20){
        for (int i = 3;i <= n;i++){
            ans += C(n,i);
            ans %= MOD;
        }
        cout << ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
