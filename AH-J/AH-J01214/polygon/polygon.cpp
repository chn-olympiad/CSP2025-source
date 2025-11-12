#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(n<=2)cout<<0;
    else if(n==3){
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
    }
    else if(a[n]==1){
        long long ans=0;
        for(int i=4;i<n;i++){
            long long cum=1;
            for(int j=n;j>=n-i+1;j--)cum=cum*a[i]%998244353;
            ans=(ans+cum)%99824453;
        }
        cout<<(ans+1)%99824453;
    }
    return 0;
}
