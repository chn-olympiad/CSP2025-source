#include<bits/stdc++.h>
using namespace std;
int n,m,t=1;
    int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int w[n+1][m+1],a[n*m+1];

    int r=a[1];
    sort(a+1,a+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            t=i;
        }
    }
    if(n==1){
        cout<<1<<' '<<t;
    }
    else if(m==1){
        cout<<t<<' '<<1;
    }
    else if(n==2 and m==2){
        if(t==1){
            cout<<1<<' '<<1;
        }
        if(t==2){
            cout<<1<<' '<<2;
        }
        if(t==3){
            cout<<2<<' '<<2;
        }
        if(t==4){
            cout<<2<<' '<<1;
        }
    }
    return 0;
}
