#include <cstdio>
using namespace std;

int a[500005];
int dp[1005][1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);

    int cnt=0, tmp=0;
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        dp[i][i]=a[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            dp[i][j]=dp[i][j-1]^a[j];
        }
    }

    for(int i=1; i<=n; ){
        for(int j=i; j<=n; ++j){
            if(dp[i][j]==k){
                ++cnt;
                i=j+1;
                break;
            }
            if(j==n)++i;
        }
    }
    printf("%d",cnt);

    return 0;

}
