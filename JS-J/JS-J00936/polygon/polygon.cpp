#include<bits/stdc++.h>
using namespace std;
int n;
int ticks[6000];
int mx=INT_MIN;
int all;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ticks[i];
        mx=max(mx,ticks[i]);
        all+=ticks[i];
    }
    if(n<3){
        cout<<0;
    }
    if(n==3){
        if(all>2*mx){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
