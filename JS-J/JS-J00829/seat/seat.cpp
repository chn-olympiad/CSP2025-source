#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],f[110],xr,c,r,cnt=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;++i)scanf("%d",&a[i]);
    xr=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;++i){
        f[i]=a[n*m-i-1];
        if(f[i]==xr)cnt=i;
    }
    c=cnt/n+1;
    if(c%2==1)r=cnt%n+1;
    if(c%2==0)r=n-cnt%n;
    cout<<c<<" "<<r;
    return 0;
}

