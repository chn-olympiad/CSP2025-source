#include<bits/stdc++.h>
using namespace std;
int n,m,one,noone,ans,c=1,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>one;
    for(int i=2;i<=n*m;i++){
        cin>>noone;
        if(one<noone) ans++;
    }
    while(ans>=m){
        c++;
        ans-=m;
    }
    if(c%2==1) r=ans+1;
    else r=m-ans;
    cout<<c<<' '<<r;
    return 0;
}
