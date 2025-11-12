#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
const int N = 5e3+8;
long long qpow(long long a,long long p){
    long long ans = 1;
    while(p){
        if(p & 1) ans = (ans * a) % mod;
        p >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
//long long up[N];
//int rec[N];
int n;
int a[N];
//int c[N][N];
//int pc[N];
//int all[N];
//int dp[N][N];
//first: i 1 --> n,second: the C of polygon (less)
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];

    }
    /*
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++){
        pc[i] = pc[i-1] + a[i];
    }

    up[1] = 1;
    up[0] = 1;
    for(int i = 2; i <= n ;i++){
        up[i] = up[i-1] * i % mod;
        up[i] = qpow(up[i],mod-2);
    }
    long long sum = 0;
    for(int i = 3; i <= n; i++){
        sum = (sum + up[n]/up[n-i]/up[i]) % mod;
        all[i] = sum;
    }

    for(int i = 0; i <= n; i++){
        c[i][pc[i]] = all[i];
    }

    //qian i,C = j,certainly mx = a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            dp[2][a[i] + a[j]] = 1;
        }
    }
    for(int i = 3; i <= n; i++){
       for(int j = a[i] + 1; j <= pc[i]; j++){
            dp[i][j] += dp[i-1][j - a[i]];
       }
    }
    int ans = 0;
    for(int i = 3; i <= n; i++){
        for(int j = a[i] + 1; j <= pc[i]; j++){
            ans += dp[i][j];
        }
    }
    cout << ans;
    //Wrong 30 pts
    */
    int mx = max(a[1],max(a[2],a[3]));
    int s = a[1] + a[2] + a[3];
    if(s > mx*2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    //15 pts
    return 0;
}
