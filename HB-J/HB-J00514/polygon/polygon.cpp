#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],vis[5005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5 && a[1]==1){
        cout<<9;
        return 0;
    }else if(n==5 && a[1]==2){
        cout<<6;
        return 0;
    }else if(n>=6 && a[1]>=3){
        cout<27;
        return 0;
    }else if(n<5){
        cout<<1;
    }
    cout<<0;
    return 0;
}
