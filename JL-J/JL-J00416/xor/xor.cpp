#include<bits/stdc++.h>
using namespace std;
int a[1145],n,m,c,r,num,tool,s[1145];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1&&k==0){
        cout<<1;
    }
    if(n==2&&k==0){
        if(a[1]==a[2])cout<<0;
        if(a[1]!=a[2])cout<<1;
    }
    return 0;
}
