#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10005],t=1,mod=998244353;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            t=0;
        }
    }
    sort(a+1,a+n+1);
    if(t==1){
        cout<<((n-2)*(n-1)/2)%mod;
    }else{
        cout<<1;
    }
    return 0;
}
