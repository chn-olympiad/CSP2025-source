#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200],d,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]>=a[1])d++;
    }
    if(d%n==0){y=d/n;}
    else {y=d/n+1;}
    if(y%2==1){
        if(d%n==0){x=n;}
        else {x=d%n;}
    }
    else{
        if(d%n==0){x=1;}
        else {x=n-d%n+1;}
    }
    cout<<y<<' '<<x;
    return 0;
}
