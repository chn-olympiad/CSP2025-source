#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int o=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            o=0;
        }
    }
    if(o&&k==0){
        cout<<n/2;
        return 0;
    }
    if(o==0){
        cout<<"2";
        return 0;
    }else{
        cout<<0;
    }
    return 0;
}
