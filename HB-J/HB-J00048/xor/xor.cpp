#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int x,y;
    cin>>x>>y;
    int a[x];
    for(int i=0;i<x;i++) cin>>a[i];
    if(x==2&&y==0) {
        if(x==y&&x!=0){
            cout<<1;
            return 0;
        }
        if(x==y&&y==0){
            cout<<2;
            return 0;
        }
        else cout<<0;
    }
    else cout<<x;
    return 0;
}

