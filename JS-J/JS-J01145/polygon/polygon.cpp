#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[3]+a[2]<=a[1]){
            cout<<0;
            return 0;
        }
        cout<<1;
        return 0;
    }
    return 0;
}
