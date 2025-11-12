#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long s[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,mx=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mx=max(mx,a[i]);
            if(s[i]-s[j-1]>2*mx){
                ans++;
            }
        }
    }
    cout<<ans%998244353;
}
