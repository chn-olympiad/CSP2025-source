#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int k,n,i,j,a[500001]={},f=0,mx=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if((a[1]+a[2]+a[3])>mx*2)cout<<1;
       else cout<<0;
    return 0;
}
