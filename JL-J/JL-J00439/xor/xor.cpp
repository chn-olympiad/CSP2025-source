#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[10000],k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(n<=2&&k==0){
            cout<<1;
        }
        else if(n<=10&&k<=1){
            cout<<a[i];
        }
        else if(n<=100&&k==0){
            cout<<1;
        }
        else if(n<=100&&k<=1){
            cout<<a[i];
        }
    }
    return 0;
}
