#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int a[MAXN] , dp[MAXN] , sum[MAXN];
int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , k;
    cin>>n>>k;
    for(int i = 1 ; i <= n ; ++i){
        cin>>a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    /*for(int i = 1 ; i <= n ; ++i){
        cout<<sum[i]<<" ";
    }
    cout<<"\n";*/
    for(int i = 1 ; i <= n ; ++i){
        dp[i] = dp[i - 1];
        for(int j = i ; j >= 1 ; --j){
            if(dp[j] + 1 <= dp[i]) break;
            if(j) dp[i] = max(dp[i] , dp[j - 1] + ((sum[i] ^ sum[j - 1]) == k));
            //else dp[i] = max(dp[i] , int((sum[i] ^ sum[j]) == k));
        }
    }
    /*for(int i = 1 ; i <= n ; ++i){
        cout<<dp[i]<<" ";
    }*/
    cout<<dp[n];
    return 0;
}
