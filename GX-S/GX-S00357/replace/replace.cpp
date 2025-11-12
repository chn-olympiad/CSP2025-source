#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(q==1){
        cout<<n-2;
    }else{
        cout<<n-1;
    }
    return 0;
}
