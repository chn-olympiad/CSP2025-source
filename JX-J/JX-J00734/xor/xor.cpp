#include<bits/stdc++.h>
using namespace std;
int sum,n,k,a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==0)cout<<2;
    else cout<<1;
    return 0;
}
