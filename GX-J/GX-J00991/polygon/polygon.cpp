#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int k,m=0,n=0;
    cin>>k;
    int a[k];
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    if(k==3){
        for(int i=0;i<k;i++){
            m=max(m,a[i]);
            n=n+a[i];
        }
        if(m*2<n){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
