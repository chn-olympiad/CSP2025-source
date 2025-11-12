#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5005],b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];

    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            if(b[j+i]-b[j]>a[j+i]*2){
                ans=(ans+i)%998244353;
            }
        }
    }
    cout<<ans%998244353-1;





    return 0;
}
