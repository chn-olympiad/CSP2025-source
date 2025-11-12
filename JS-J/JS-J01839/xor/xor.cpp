#include<bits/stdc++.h>
using namespace std;
long long  n,k,l[50005],dp[10001][10001],pp[10001][10001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>l[i];
    }
    for (int i=1;i<=n;i++){
            for (int j=1;j<=i;j++){
                long long a = dp[j][i-1]^l[i];
                dp[j][i]=a;
            }
        }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            pp[j][i]=pp[j-1][i-1];
            if(dp[j][i]==k){
                pp[j][i]++;
            }
        }
    }
    long long ma=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
           ma=max(ma,pp[i][j]);
        }

    }
    cout<<ma;
    return 0;
}
