#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
long long ans;
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if (n<3){
        ans=0;
    }
    else if (n==3){
        if(a[1]+a[2]>a[3]){
            ans=1;
        }
        else{
            ans=0;
        }
    }
    else if(a[n]==1){
        for (int i=3;i<=n;i++){
            long long p=1;
            long long q=1;
            for (int j=1;j<=i;j++){
                p=p*(n-j+1);
                q=q*(i-j+1);
            }
            ans=(ans+p/q)%mod;
        }
    }
    else{
        ans=9;
    }
    cout<<ans;
    return 0;
}


