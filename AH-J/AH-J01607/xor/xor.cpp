#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
LL dp[500005],a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=dp[i-1]^a[i];
    }
    LL cnt=1,l=1,r=1,ans=dp[0];
    n*=n;
    while(n--){
        for(LL j=l;j<=r;j++) ans=ans^dp[j];
        if(ans==k){
            cnt++;
            l=r;
            r++;
        }
        else r++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
