#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,m=0,a[10]={};
    cin>>n;
    for(int i=1;i<=3;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(a[1]+a[2]+a[3]>a[3]*2){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
