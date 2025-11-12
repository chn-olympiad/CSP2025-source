#include <iostream>
#include <cstdio>
using namespace std;
int mc=1,n,m,c,r;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    for(int i=0;i<n*m;i++) cin>>a[i];

    for(int i=1;i<n*m;i++){
        if(a[0]<a[i]) mc++;
    }

    if(mc<=n){
        c = 1;
        r = mc;
    }
    else if(mc %n == 0){
        c = mc/n;
        if(c%2==1) r=n;
        else r=1;
    }
    else{
        c = mc/n+1;
        if(c%2==1) r=mc%n;
        else r = n + 1 - (mc - (c-1)*n);
    }

    cout<<c<<" "<<r;
    return 0;
}
