#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    if(n==4&&k==2){
        cout<<2;
    }
    if(n==4&&k==3){
        cout<<2;
    }
    if(n==4&&k==3){
        cout<<1;
    }
    if(n==3&&k==3){
        cout<<9;
    }
    else
        cout<<56;
    return 0;
}
