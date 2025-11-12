#include<bits/stdc++.h>
using namespace std;
int n,k,dp[110000],a[110000],nm[110000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        nm[i] =a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(a[j] ^ nm[i] == k){
                dp[j] = dp[i] + 1;
            }else{
            dp[j] = 0;
            }
        }
    }
    cout << dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
