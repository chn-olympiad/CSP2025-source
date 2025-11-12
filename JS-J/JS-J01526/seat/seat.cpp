#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,m,n,k,kx,x,y,a[111];
    cin>>n>>m;
    l=m*n;
    for(int i=0;i<l;i++)cin>>a[i];
    x=a[0];
    sort(a,a+l);
    for(int i=0;i<l;i++)if(a[i]==x)k=i;
    kx=l-k;
    y=(kx-1)/n+1;
    cout<<y<<" ";
    if(y%2==1){
        if(kx%n==0)cout<<n;
        else cout<<(kx%n);
    }
    if(y%2==0)cout<<(n*y-kx+1);
    return 0;
}
