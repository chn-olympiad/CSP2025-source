#include<bits/stdc++.h>
using namespace std;
int n,a[10000000],k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=a[i]^=a[2];
    if(n==2&&x==k){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
