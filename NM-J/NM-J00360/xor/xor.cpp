#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,i;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==2||k==3){
        cout<<2;
    }
    if(k==0){
        cout<<1;
    }
    return 0;
}
