#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3&&max(a[1],a[2],a[3]<sum){
        cout<<1;
        return 0;
    }
}
