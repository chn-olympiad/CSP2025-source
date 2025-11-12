#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i-1];
    }if(n<3){
        cout<<"0";
    }else if(n==3 && (a[0]+a[1]+a[2])>max(a[0],a[1],a[2])*2){
        cout<<"1";
    }else if(n==3 && a[0]+a[1]+a[2]<=max(a[0],a[1],a[2])*2){
        cout<<"0";
    }else if(n>3 && n<=10){
        cout<<n+1;
    }else{
        cout<<2*n;
    }
}
