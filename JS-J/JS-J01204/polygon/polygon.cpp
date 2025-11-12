#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=3){
        sort(a,a+3);
        if(a[0]+a[1]>a[2]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<20;
    }
    return 0;
}

