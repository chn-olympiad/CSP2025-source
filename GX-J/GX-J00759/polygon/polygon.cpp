#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int ans,M=-0x3f;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        M=max(a[i],M);
        ans+=a[i];
    }
    if(ans>M*2)cout<<1;
    else cout<<0;
    return 0;
}
