#include<bits/stdc++.h>
using namespace std;

int n,s=0;
int a[5001];
int b[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>a[i];
       if(s==1){
        s++;
       }
    }
    sort(a+1,a+1+n);
    if(n==3){
        b[1]=a[1];
        for(int i=1;i<=n;i++){
            b[i]=a[i]+b[i-1];
        }
        if(b[n]>a[n]*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
