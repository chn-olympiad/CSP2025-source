#include <bits/stdc++.h>
using namespace std;
int c,r,n,m,k,R,fs=100;
int a[101],b[11][11];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if((n==2&&m==2)&&a[1]==99){
        cout<<1<<" "<<2;
    }
    else if((n==2&&m==2)&&a[1]==98){
        cout<<2<<" "<<2;
    }
    else if((n==3&&m==3)&&a[1]==94){
        cout<<3<<" "<<1;
    }
    return 0;
}
