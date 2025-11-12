#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,x,c,r,d,i;
    cin>>n>>m;
    int a[n*m+1]={0};
    for(i=1; i<=n*m; i++) cin>>a[i];
    d=a[1];
    sort(a+1,a+n*m+1);
    for(i=1; i<=n*m; i++){
        if(a[i]==d)  b=i;
    }
    b=m*n-b+1;
    x=2*n;
    if(b%x<=n)  r=b%x;
    else if(b%x>n) r=n-(b%x-n)+1;
    if(b%n==0 && b/n!=0) c=b/n;
    else c=b/n+1;
    cout<<c<<' '<<r;
    return 0;
}
