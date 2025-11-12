#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n],z=0,f=0;
    for(int i;i<n;i++){
        cin>>a[i];
        z=z+a[i];
    }
    if(n==3){
        cout<<1;
        return 0;
    }
    sort(a,a+n);
    for(int i;i<n;i++){
            if(a[n-i]>z) f++;
    }
    cout<<f%998%244%353;
    return 0;
}
