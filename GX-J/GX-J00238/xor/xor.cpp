#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,n1,n2,A=0;
    cin>>n>>k;
    if(n>1){
        cin>>n1>>n2;
        if(n1==n2){
            A++;
        }
        if(n1==0){
            A++;
        }
        if(n2==0){
            A++;
        }
        cout<<A;
    }else{
        cin>>n1;
        if(n1==0) cout<<1;
        else cout<<0;
    }


    return 0;
}
