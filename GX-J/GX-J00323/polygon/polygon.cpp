#include<bits/stdc++.h>
using namespace std;
int n;
int a[5100];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            a[i]=a[i-1];
        }else if(a[i-1]<a[i+1]){
            a[i]=a[i+1];
        }
        if(a[i]+a[i-1]+a[i+1]>2*a[i]){
            cout<<a[i]<<" "<<a[i+1]<<" "<<a[i-1];
        }
    }
    return 0;
}
