#include<bits/stdc++.h>
using namespace std;
int a[12][12],n,m,b[110],k,t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    k=b[1];
    sort(b+1,b+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(b[i]==k){
            t=n*m-i+1;
        }
    }
    if(n==1&&m==1){
        cout<<1<<" "<<1;
        return 0;
    }
    if(n==1&&m<=10){
        cout<<1<<" "<<t;
        return 0;
    }
    if(n<=10&&m==1){
        cout<<t<<" "<<1;
        return 0;
    }
    if(n<=2&&m<=2){
        if(k==b[n*m]) cout<<1<<" "<<1;
        if(k==b[n*m-1]) cout<<1<<" "<<2;
        if(k==b[n*m-2]) cout<<2<<" "<<2;
        if(k==b[1]) cout<<2<<" "<<1;
        return 0;
    }
    return 0;
}
