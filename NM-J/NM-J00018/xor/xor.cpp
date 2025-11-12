#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,k,ans,p;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        p=p^a[i];
        if(p==k) ans++,p=0;
        //cout<<i<<":"<<ans<<' '<<p<<' ';
    }
    cout<<ans;
    return 0;
}