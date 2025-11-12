#include <bits/stdc++.h>
using namespace std;
int a[111],k,n,m,b,c,r,tot;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    tot=n*m;
    for(int i=1;i<=tot;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+tot+1);
    for(int i=1;i<=tot;i++){
        if(a[i]==k)b=tot+1-i;
    }
    c=(b-1)/n+1;
    if(c%2==1){
        if(b%n==0)r=n;
        else r=b%n;
    }
    if(c%2==0){
        if(b%n==0)r==1;
        else r=n+1-b%n;
    }
    cout<<c<<" "<<r;
    return 0;
}
