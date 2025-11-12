#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int self;cin>>self;
    int rk=1;
    for(int i=2;i<=n*m;i++){
        int a;cin>>a;
        rk+=(a>self);
    }
    int k=ceil(rk*1.0/n);
    int x=k,y;
    if(k&1){//2s+1
        y=rk%n;
        if(!y)y+=n;
    }
    else y=n-(rk%n)+1;
    cout<<x<<' '<<y;
    return 0;
}
