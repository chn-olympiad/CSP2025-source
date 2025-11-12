#include <bits/stdc++.h>
using namespace std;
int n,a[5005],m=-1;
long long mod=998244353;
long long ans,c[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        m=max(a[i],m);
    }
    if(n<3){
        cout << 0 << endl;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>m*2){
            cout << 1 << endl;
            return 0;
        }
    }
    if(m==1){
        for(int i=3;i<=n;i++){
            long long f=1;
            for(int j=1;j<=i;j++){
                f=f*(n+1-j)/j;
            }
            ans=(ans+f)%mod;
        }
        cout << ans << endl;
        return 0;
    }
    sort(a+1,a+n+1);
    c[1]=1;
    c[2]=1;
    if(a[1]+a[2]>a[3]){
        c[3]=1;
    }
    for(int i=4;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            c[i]=(c[i]+c[j])%mod;
        }
    }
    cout << c[n] << endl;
    return 0;
}
