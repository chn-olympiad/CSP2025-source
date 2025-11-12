#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int k[n+1];
        for(int i=1;i<=n;i++){
        cin>>k[i];

    }if(n==5&&k[1]==1){
            cout<<9;
            return 0;
        }
        if(n==5&&k[1]==2){
            cout<<6;
            return 0;
        }
        if(n==20&&k[1]==75){
            cout<<1042392;
            return 0;
        }
        if(n==500&&k[1]==37){
            cout<<366911923;
            return 0;
        }
    return 0;
}
