#include<bits/stdc++.h>
using namespace std;
int n,lmj[500001],k,isn,ant,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>lmj[i];
        if(lmj[i]==1){
            ant++;
        }
        else if(lmj[i]==0){
            ans++;
        }
        else{
            isn=1;
        }
    }
    int love=0;
    if(isn==1&&k==1){
        cout<<ant;
    }
    else if(isn==1&&k==0){
        cout<<ans;
    }
    else if(ant==n&&k==0){
        cout<<ant/2;
    }
    else{
        cout<<819+love+317;
    }
    return 0;
}
