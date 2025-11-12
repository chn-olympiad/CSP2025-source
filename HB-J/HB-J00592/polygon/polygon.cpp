#include<bits/stdc++.h>
using namespace  std;
int n,a[5005],x[5005],bi=-1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a[i];
        x[i]=x[i-1]+a[i];
        if(a[i]>bi){
            bi=a[i];
        }
    }
    if(n==3){
        if(a[3]>bi*2){
            cout<<1;
            return 0;
        }
        cout<<0;
    }
    return 0;
}
