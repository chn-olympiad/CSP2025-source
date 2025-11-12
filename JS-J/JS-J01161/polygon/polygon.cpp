//2025CSP-J/S rp++
//please be a nice score!
//I wish I can get 360 pts
#include <bits/stdc++.h>
using namespace std;

long long a[5055];
long long dp[5055][5055];
long long sum[5055][5055];
long long ans2 = 0;
long long n, f = 1;
const long long mod = 998244353;

void dfs(int x, int sum, int cnt, int pos){
    ans2++;
    //cout << setw(cnt) << "!\n";
    for(int i = (lower_bound(a + 1, a + n + 1, sum) - a);i <= n;i++){
        if(i == pos) continue;
        //cout << setw(cnt) << a[i] << "\n";
        dfs(a[i], sum + a[i], cnt + 1, i);
    }
    return ;
}

long long fastexp(long long a, long long b){
    if(a == 0) return 1;
    if(a == 1) return b;
    long long x = fastexp(a / 2, b);
    if(a % 2) return (((x * x) % mod) * b) % mod;
    else return (x * x) % mod;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            f = 2;//plan B
        }
    }
    if(f == 1){
        //plan A
        //20 pts
        cout << (fastexp(n, 2) + mod - (n * (n - 1)) / 2 - n - 1) % mod;
    }
    else if(f == 2 && n <= 20){
        //plan B
        //40 pts
        long long mx, sum2, ans = 0;
        for(long long i = 1;i < (1 << (n));i++){
            //cout << bitset<8>(i) << "\n";
            mx = -1, sum2 = 0;
            for(long long j = 1;j <= n;j++){
                if(1 & (i >> (j - 1))){
                    mx = max(mx, a[j]);
                    sum2 += a[j];
                }
            }
            if(sum2 > mx * 2){
                //cout << sum << " " << mx << "\n";
                ans = (ans + 1) % mod;
            }
        }
        cout << ans << "\n";
    }
    else{
        //plan C
        //40 pts
        //It's difficult!
        //I give up :(

        sort(a + 1, a + n + 1);
        dfs(0, 0, 0, -1);
        cout << (fastexp(n, 2) - ans2) % mod << "\n";

    }
    return 0;
}
