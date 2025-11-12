#include <bits/stdc++.h>
using namespace std;
int m,n,k,u=0,u1,c,r;
int main(){
    freopen("seat3.in","r",stdin);
    freopen("seat3.out","w",stdout);
    cin>>n>>m;
    int a[m*n];
    cin>>k;
    a[1]=k;
    for(int i=2;i<=m*n;i++) cin>>a[i];
    for(int i=1;i<=m*n;i++)
        if(a[i]>k) u++;
    u++;
    u1=u%n;
    c=((u-u1)/n)+1;
    if(c%2==0) n-(u1-1);
    else r=u1;
    cout<<c<<" "<<r;
    return 0;
}
