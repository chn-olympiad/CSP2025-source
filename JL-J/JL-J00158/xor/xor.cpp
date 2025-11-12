#include<bits/stdc++.h>
using namespace std;
int n,k,a[3];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[0]==k and a[1]==k){
        cout<<2<<endl;
    }
    if((a[0]^a[1])==k){
        cout<<1<<endl;
    }
    return 0;
}
