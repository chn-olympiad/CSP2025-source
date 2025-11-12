#include<bits/stdc++.h>
using namespace std;

int n,a[15];

int main(void){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[2]>ans(a[1]-a[3])&&a[2]<a[1]+a[3]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
