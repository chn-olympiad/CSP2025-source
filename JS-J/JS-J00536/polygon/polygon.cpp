#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }sort(a,a+n);
    if(a[n-1]*2<s){
        cout<<1;
    }else{
        cout<<0;
    }


    return 0;
}
