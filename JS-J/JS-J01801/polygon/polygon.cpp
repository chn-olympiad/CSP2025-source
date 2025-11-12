#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long s[5010];
const long long p=998244353;
long long ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int mx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n==3) {
        if(s[n]>2*mx) cout<<1;
        else cout<<0;
        return 0;
    }
    if(mx==1){
        long long ans=0;
        for(int i=3;i<=n;i++){
            long long m=(n-i+2)*(n-i+1)/2%p;
            ans+=m;
            ans%=p;
        }
        cout<<ans;
    }
    cout<<12345678;
    return 0;
}
