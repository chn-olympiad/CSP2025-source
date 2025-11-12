#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n=1){
        if(k==a[1]) cout<<1;
        else cout<<0;
    }
    if(n=2){
        if(k==a[1]&&a[2]==k) cout<<2;
        else if(a[1]^a[2]==k) cout<<1;
        else cout<<0;
    }
    return 0;
}
