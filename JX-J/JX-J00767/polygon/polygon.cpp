#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n;
int a[1000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        sort(a,a+1+n);
        if(a[1]+a[2]>a[3])
            cout<<1;
        else cout<<0;
        return 0;
    }
    long long ans=0;
    long long t=n*(n-1)*(n-2);
    long l=1;
    for(int i=3;i<=n;i++){
        ans+=l*t;
        l*=(n-i);
        ans=ans%mod;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
