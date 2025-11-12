#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,Rs,r,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            Rs=n*m+1-i;
            break;
        }
    }
    if(Rs%n==0) c=Rs/n;
    else c=(Rs/n)+1;
    if(c%2==1){
        if(Rs%n==0) r=n;
        else r=Rs%n;
    }
    else{
        if(Rs%n==0) c=1;
        else r=n-Rs%n+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
