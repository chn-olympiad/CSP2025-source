#include<bits/stdc++.h>
#define int long long
constexpr int mod=998244353;
using namespace std;
int qpow(int a,int b,int m) {
    int ans=1;
    while (b) {
        if (b&1) {
            ans=ans*a%m;
        }
        a=a*a%m;
        b>>=1;
    }
    return ans;
}
signed main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxx=1;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if (n<3) {
        cout<<"0\n";
        return 0;
    }
    if (n==3) {
        cout<<(a[0]+a[1]+a[2]>2*maxx)%mod<<"\n";
        return 0;
    }
    if (maxx==1) {
        int ans=0;
        vector<int> sum(n+5,1);
        for (int i=1;i<n+5;i++) {
            sum[i]=sum[i-1]*i;
        }
        for (int i=3;i<=n;i++) {
            int sum1=sum[n]*qpow(sum[n-i],mod-2,mod)%mod;
            int sum2=sum[i];
            sum1=sum1*qpow(sum2,mod-2,mod)%mod;
            ans+=sum1;
            ans%=mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    int ans=0;
    for (int i=0;i<(1<<n);i++) {
        bitset<20> bt=i;
        if (bt.count()<3) {
            continue;
        }
        int sum=0,maxxx=0;
        for (int j=0;j<n;j++) {
            if (bt[j]==1) {
                maxxx=max(maxxx,a[j]);
                sum+=a[j];
            }
        }
        if (sum>2*maxxx) {
            ans++;
            ans%=mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
