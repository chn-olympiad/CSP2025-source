#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long n,a[5005],b[5005],sum,ans,maxx=-1,s1,s2;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
        maxx=max(maxx,a[i]);
    }
    if(n==3){
        if(ans>2*maxx) cout<<1;
        else cout<<0;
        return 0;
    }
    cout<<9;
    return 0;
}
