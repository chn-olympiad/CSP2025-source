#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
ll n , k , maxn;
ll a[500010];
ll b[500010];
ll c[500010];
ll dp[500010];
int main(){
    IOS
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    for (int i = 1 ; i <= n ; i ++ ) a[i] ^= a[i-1];
    memset (b , -1 , sizeof b);
    b[0] = 0;
    for (int i = 1 ; i <= n ; i ++ ) {
        dp[i] = dp[i - 1];
        if (b[(k^a[i])] != -1) dp[i] = max (dp[i] , dp[b[(k^a[i])]] + 1);
        b[a[i]] = i;
        maxn = max (maxn , dp[i]);
    }
    cout << maxn;
    return 0;
}
