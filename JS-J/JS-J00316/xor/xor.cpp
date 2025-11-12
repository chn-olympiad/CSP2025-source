#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
long long a[maxn];
long long sum[maxn], dp[maxn];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, k;
    cin>>n>>k;
    for(int i = 1;i <= n;++i)  cin>>a[i];
    for(int i = 1;i <= n;++i)  sum[i] = sum[i - 1] ^ a[i];

    for(int i = 1;i <= n;++i){
        //not add
        dp[i] = dp[i - 1];

        //add
        long long tmp = a[i] ^ k;
        for(int j = i;j >= 1;--j){
            long long yi = sum[i - 1] ^ sum[j - 1];
            if(yi == tmp){
                dp[i] = max(dp[i], dp[j - 1] + 1);
                break;
            }
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
