#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long dp1[10005];
long long dp2[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long sum=0,ans=0;
    dp2[0]=1;
    for(long long i=1;i<=2;i++){
        for(long long j=10000-a[i]+1;j<=10000;j++){
            sum+=dp2[j];
            sum%=998244353;
        }
        for(long long j=10000;j>=a[i];j--){
            dp2[j]+=dp2[j-a[i]];
            dp2[j]%=998244353;
        }
    }
    for(long long i=3;i<=n;i++){
        for(long long j=10000-a[i]+1;j<=10000;j++){
            sum+=dp2[j];
            sum%=998244353;
        }
        for(long long j=10000;j>=a[i];j--){
            dp1[j]=dp2[j-a[i]];
            dp2[j]+=dp2[j-a[i]];
            dp1[j]%=998244353;
            dp2[j]%=998244353;
        }
        for(long long j=a[i]*2+1;j<=10000;j++){
            ans+=dp1[j];
            ans%=998244353;
        }
        ans+=sum;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
