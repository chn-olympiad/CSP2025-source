#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    b=a[1];
    sort(a+1,a+n*m+1);
    int i;
    for(i=n*m;i>=1&&a[i]!=b;i--);
    i=n*m-i+1;
    if(i%m==0){
        if((i/m)%2==1)cout<<i/m<<" "<<n;
        else cout<<i/m<<" "<<1;
    }
    else{
        if((i/m+1)%2==1)cout<<i/m+1<<" "<<1+i%m-1;
        else cout<<i/m+1<<" "<<n-1%m+1;
    }
    return 0;
}
