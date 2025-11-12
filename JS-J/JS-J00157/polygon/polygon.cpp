#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    bool flag=1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=0;
    }
    if(flag){
        long long ans=0;
        for(long long i=3;i<=n;i++){
            long long cnt=1;
            for(long long j=n;j>n-i;j--){
                cnt*=j;
                cnt%=mod;
            }
            for(long long j=2;j<=i;j++){
                cnt/=j;
                cnt%=mod;
            }
            ans+=cnt;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    long long ans=0;
    long long cnt;
    long long maxn,sum;
    for(long long i=1;i<(1<<n);i++){
        maxn=0;
        sum=0;
        cnt=0;
        for(long long j=0;j<n;j++){
            if(i&(1<<j)){
                cnt++;
                sum+=a[j+1];
                maxn=max(maxn,a[j+1]);
            }
        }
        if(cnt>=3&&sum>maxn*2){
            ans++;
            ans%=mod;
        }
    }
    cout<<ans;
    return 0;
}
