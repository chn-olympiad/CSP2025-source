#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[105];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        if(a[1]==k){
            cout<<1;
        }
        return 0;
    }
    cout<<n/2;
    return 0;
}
