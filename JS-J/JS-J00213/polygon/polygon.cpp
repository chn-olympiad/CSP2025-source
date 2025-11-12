#include<bits/stdc++.h>
using namespace std;
// /xia LuoFeng_Nanami
const int N=5e3+5,P=998244353;
int a[N],dp[N],sum,ans;
inline int add(int x,int y){
    return (x+y)%P;
}
inline int solve(int x){
    int ret=sum;
    for (int i=a[x]+1;i<=5000;i++) ret=add(ret,dp[i]);
    sum=add(sum,sum);
    for (int i=5000-a[x]+1;i<=5000;i++) sum=add(sum,dp[i]);
    for (int i=5000;i>=a[x];i--) dp[i]=add(dp[i],dp[i-a[x]]);
    return ret;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    dp[0]=1,dp[a[1]]+=1,dp[a[2]]+=1;
    if (a[2]+a[1]<=5000) dp[a[2]+a[1]]+=1;
    else sum++;
    for (int i=3;i<=n;i++) ans=add(ans,solve(i));
    cout<<ans;
    return 0;
}