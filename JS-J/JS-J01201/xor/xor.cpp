#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 2e6+10;
int a[N],b[N],dp[N],lt[M];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(lt,-1,sizeof lt);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
    dp[0]=0; lt[k]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(lt[b[i]]>=0) dp[i]=max(dp[i],dp[lt[b[i]]]+1);
        lt[b[i]^k]=i;
    }
    cout<<dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
