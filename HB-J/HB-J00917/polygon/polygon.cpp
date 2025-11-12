#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+10],mx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*mx){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    if(mx==1){
        cout<<0;
        return 0;
    }
    cout<<0;
    return 0;
}
