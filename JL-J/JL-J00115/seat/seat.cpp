#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],t[105],y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int x=a[1];
    sort(a+1,a+n+1);
    for(int i=n*m;i>=1;i--)
        t[i]=a[n*m-i+1];
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            y=i;
            break;
        }
    }
    cout<<y;

    if(y%m==0){
        c=y/m;
        if(c%2) r=m;
        else r=1;
    }
    else{
        c=y/m+1;
        if((y/m+1)%2==0) r=y%m;
        else r=m-y%m+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
