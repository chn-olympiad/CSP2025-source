#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int js=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        js+=x;
    }
    if(k==1){
        cout<<js;
    }else{
        cout<<js/2+n-js;
    }
    return 0;
}
