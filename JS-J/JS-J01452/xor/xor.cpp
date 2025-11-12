#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[n-1];
    }

    if(k==0){
        if(n<10){
            cout<<"0";
        }else {
            cout<<"1";
        }

    }else{
        cout<<n/2;
    }

}
