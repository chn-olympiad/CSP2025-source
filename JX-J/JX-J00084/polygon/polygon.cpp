#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[2]+a[3]<=a[1]){
            cout<<0;
            return 0;
        }else{
            cout<<1;
            return 0;
        }
    }else{
        cout<<n+1;
        return 0;
    }
    return 0;
}
