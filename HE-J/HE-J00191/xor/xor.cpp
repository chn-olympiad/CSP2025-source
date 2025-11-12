#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
bool b1[20];
bool b2[500010][20];
bool b3[20];
long long dp[500010];

int main(){

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%lld", &n, &k);
    for(int i=0; k; i++, k>>=1){
        b1[i]=k&1;
    }
    for(int i=1; i<=n; i++){
        long long x=0;
        scanf("%lld", &x);
        for(int j=0; x; x>>=1, j++){
            b2[i][j]=x&1;
        }
        bool B=false;
        for(int j=0; j<=19; j++){
            b3[j]=0;
        }
        dp[i]=dp[i-1];
        for(int j=i; j>=1; j--){
            for(int l=0; l<=19; l++){
                if(b3[l]==b2[j][l]){
                    b3[l]=0;
                }else{
                    b3[l]=1;
                }
                if(b3[l]!=b1[l]){
                    B=true;
                }
            }
            if(B){
                B=false;
            }else{
                dp[i]=max(dp[j-1]+1, dp[i]);
                break;
            }
        }
    }
    printf("%lld\n", dp[n]);

    return 0;

}
