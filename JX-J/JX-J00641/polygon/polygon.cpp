#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
int n,a[5002];
ll cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        int ans=a[1]+a[2]+a[3];
        if(ans>(2*(max(a[1],max(a[2],a[3]))))) cout<<1;
        else cout<<0;
    }
    else{
        for(int i=1;i<=n-2;i++){
            for(int j=1;j<=i;j++){
                cnt+=j;
                cnt%=mod;
            }
        }
        cout<<cnt%mod;
    }
    return 0;
}