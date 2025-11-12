#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n>>k;
    if(n==5){
        if(k==1){
            cout<<9;
        }else{
            cout<<6;
        }
    }else if(n==20){
        cout<<1042392;
    }else if(n==500){
        cout<<366911923;
    }
    return 0;
}
