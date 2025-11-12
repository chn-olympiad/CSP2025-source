#include<bits/stdc++.h>
using namespace std;
int n,m,nm,a[105],c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    //sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        //if(i==1&&j==1)continue;
        if(a[i]>=a[1])nm++;
    }
    c=nm/n+1;
    if(nm<=n)c=1;
    r=nm%n;
    if(c%2==0)r=m-r+1;
    if(nm<=n)r=nm;
    cout<<c<<' '<<r;
}
