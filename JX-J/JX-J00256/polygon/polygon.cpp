#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt=0,max_=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
        max_=max(max_,a[i]);
    }
    if(cnt>max_) cout<<1;
    else cout<<0;
    return 0;
}
