#include "bits/stdc++.h"
using namespace std;
int a[105];
int m,n;
int mya,se,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    mya=a[1];
    sort(a+1,a+m*n+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==mya){
            se=i;
            break;
        }
    }
    int c=(se-1)/n+1;
    if(c%2==1){
        r=se-(c-1)*n;
    }else{
        r=n+1-(se-(c-1)*n);
    }
    cout<<c<<" "<<r;
    return 0;
}
