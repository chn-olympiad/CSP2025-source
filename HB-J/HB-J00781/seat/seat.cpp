#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],x,l,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(x==a[i]) x=i;
    }
    if(x%n==0)l=x/n;
    else l=x/n+1;
    if(l%2==0) h=n+1-x%n;
    else h=x%n;
    cout<<l<<' '<<h;
    return 0;
}
