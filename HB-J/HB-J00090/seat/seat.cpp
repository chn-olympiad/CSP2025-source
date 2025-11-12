#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,ans;
int two_f(int l,int r){
    int mi=(l+r)>>1;
    if(num==a[mi])return n*m-mi+1;
    if(num<a[mi])return two_f(l,mi); 
    if(num>a[mi])return two_f(mi,r);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i*m-m+j];
    num=a[1];
    sort(a+1,a+n*m+1);
    ans=two_f(1,n*m);
    --ans;
    cout<<ans/n+1<<" ";
    if((ans/n)%2)cout<<n-(ans%n);
    else cout<<ans%n+1;
    return 0;
}