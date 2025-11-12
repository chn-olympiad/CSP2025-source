#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a[n+5];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        if(a[1]==0){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(n==2){
        if((a[1]==0||a[2]==0)&&a[1]!=a[2]){
            cout<<1;
            return 0;
        }else{
            if(a[1]^a[2]==k){
                cout<<2;
                return 0;
            }else{
                cout<<0;
                return 0;
            }
        }
    }
    return 0;
}
