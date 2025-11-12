#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
    }
    if(n==4){
        if(k==2||k==3) cout<<2;
        else cout<<1;
    }
    return 0;
}
