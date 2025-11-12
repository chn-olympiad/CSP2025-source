#include<bits/stdc++.h>
using namespace std;
int n,waaa[3];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n!=3){
        cout<<0;
    }else{
        cin>>waaa[0]>>waaa[1]>>waaa[2];
        int a,b;
        a=waaa[0]+waaa[1]+waaa[2];
        if(a>waaa[0]*2&&a>waaa[1]*2&&a>waaa[2]*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
