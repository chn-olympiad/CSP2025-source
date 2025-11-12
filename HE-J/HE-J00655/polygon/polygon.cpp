#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5005],ans,f[10005],sum;
long long ksm(long long a,long long b){
    long long k=1;
    while(b){
        if (b&1) k=k*a%998244353;
        a=a*a%998244353;
        b>>=1;
    }
    return k;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    bool t=1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]>1) t=0;
    }
    if (t){
        cout << (ksm(2,n)%998244353-1-(n*(n+1)/2))%998244353;
        return 0;
    }
    sort(a+1,a+n+1);
    for (int t=3;t<=n;t++){
        for (long long i=3;i<=(1<<(t-1))-1;i++){
            sum=0;
            for (int j=1;j<=t-1;j++){
                if (i&(1<<(j-1))) sum+=a[j];
            }
            if (sum>a[t]) ans=(ans+1)%998244353;
        }
    }
    cout << ans%998244353;
    return 0;
}
