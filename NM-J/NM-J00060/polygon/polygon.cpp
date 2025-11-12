#include<bits/stdc++.h>
using namespace std;
int n,a[10000],s,f=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=1;
        }
    }
    sort(a,a+n);
    if(n==3){

        if(a[0]+a[1]+a[2]>2*a[2]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(f==0){
        cout<<n-2;
        return 0;
    }
    return 0;
}
