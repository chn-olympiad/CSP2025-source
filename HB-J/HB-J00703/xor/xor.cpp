#include<bits/stdc++.h>
using namespace std;

int main(){
//    freopen("xor.in","r",stdin);
//    freopen("xor.out","w",stdout);
     int n,k,a[500006];
        cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        if(a[0]==k){
            cout<<1;
        }

        else{
            cout<<0;
        }
    }
    if(n==2){

    }
    int s,b;
    cin>>s>>b;
    s<<b;
    cout<<s<<b;

    return 0;
}
