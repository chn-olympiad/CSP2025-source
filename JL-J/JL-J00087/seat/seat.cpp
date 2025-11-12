#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],b[101],c,d,e;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(b[1]==a[i])c=n*m-i+1;
    }
    if(c/n*n==c){
        d=c/n;
        if(d%2==0){
            cout<<d<<" "<<"1";
        }
        else cout<<d<<" "<<n;
    }
    else{
        d=c/n+1;
        if(d%2==0)cout<<d<<" "<<n-(c-n*(d-1));
        else cout<<d<<" "<<c-n*(d-1);
    }
    return 0;
}
