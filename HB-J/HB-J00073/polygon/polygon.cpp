#include <bits/stdc++.h>
using namespace std;
int n,a[10],s,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=max(s,a[i]);
        sum+=a[i];
    }
    if(sum>s*2) cout<<1;
    else cout<<0;
    return 0;
}
