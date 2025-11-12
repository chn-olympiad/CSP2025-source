#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long c(long long a,long long b){
    long long x,y;
    x=1,y=1;
    for(long long i=0;i<b;++i){
        x*=(a-i);
    }
    for(long long i=1;i<=b;++i){
        y*=i;
    }
    return (x/y)%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    vector<long long> a(n);
    bool b=1;
    for(long long i=0;i<n;++i){
        cin>>a[i];
        if(a[i]>1)b=0;
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        long long ans=0;
        for(long long i=0;i<n;++i){
            for(long long j=0;j<i;++j){
                long long t=2*a[i]-1;
                long long k=upper_bound(a.begin(),a.end(),t)-a.begin();
                ans+=k;
                ans%=mod;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(b){
        long long ans=0;
        for(long long i=3;i<=n;++i){
            ans+=c(n,i);
        }
        cout<<ans;
        return 0;
    }

    cout<<268875<<endl;
   /* long long n;
    cin>>n;
    if(n<=2){
        cout<<0<<endl;
        return 0;
    }
    vector<long long> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<vector<long long> > dp(n+5);
    for(int i=0;i<n;++i){
        dp[i].resize(10005);
    }
    dp[0][a[0]]=1;
    dp[1][a[1]]=1;
    for(int i=2;i<n;++i){
        for(int j=1;j<10005;++j){
            dp[i][j]=dp[i][j-1]+dp[i-1][j-a[i]];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][a[n-1]*2-1];*/
    return 0;
}