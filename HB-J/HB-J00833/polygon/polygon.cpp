#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxa,sum;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        sum+=a[i];
    }
    if(n==3) cout<<(sum>2*maxa?1:0);
    if(n<3) cout<<0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    solve();
    return 0;
}
