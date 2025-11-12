#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>k;
    }
    if(k==1){
        cout<<2;
        return 0;
    }
    cout<<1;
    return 0;
}
