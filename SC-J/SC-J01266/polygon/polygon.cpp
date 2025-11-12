#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=5005,MOD=998244353;
int n,a[N];
i64 dp[N];
void Work(){
    cin>>n;
    i64 ans=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        (ans<<=1)%=MOD;
    }
    sort(a+1,a+n+1);
    dp[0]=1,--ans;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=a[i];++j) (ans-=dp[j])%=MOD;
        for(int j=5000;j>=a[i];--j) (dp[j]+=dp[j-a[i]])%=MOD;
    }
    printf("%lld\n",(ans+MOD)%MOD);
}
int main(){
    freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}