#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[105];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n==3&&a[1]+a[2]>a[3]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(a[n]==1){
        cout<<n-2;
        return 0;
    }
    return 0;
}
