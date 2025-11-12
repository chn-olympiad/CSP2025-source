#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int maxn = 5010;
const int mod = 998244353;
int n;
int a[maxn];

int dfs(int sum, int maxx, int step, int st){
    if (step == 0){
        if (sum > maxx * 2) return 1;
        return 0;
    }

    int ans = 0;
    for (int i=st; i<=n-step+1; i++){
        ans += dfs(sum+a[i], max(maxx, a[i]), step-1, i+1);
    }

    return ans;
}

signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;

    bool flag = true;

    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i] != 1) flag = false;
    }

    if (!flag){
        int ans = 0;
        for (int i=3; i<=n; i++){
            ans += dfs(0, 0, i, 1);
            ans %= mod;
        }
        cout << ans;
    }else{
        int ans = 0, k=1, s=1;
        for (int i=1; i<=n; i++){
            s *= i;
            s %= mod;
            k *= (n-i+1);
            k %= mod;

            if (i < 3) continue;
            ans += k / s;
            ans %= mod;
        }
        cout << ans;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
