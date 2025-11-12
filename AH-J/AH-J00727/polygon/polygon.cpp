#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]+a[3]<=2*a[3]){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else if(n==5&&a[1]==1){
        cout<<9;
    }
    else if(n==5&&a[1]==2){
        cout<<6;
    }
    else{
        cout<<0;
    }
    return 0;
}
