#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i) cin>>a[i];
    int ls=a[1];
    sort(a+1,a+n*m+1);
    int k=1;
    for(;k<=n*m;++k)
        if(a[k]==ls)
            break;
    k=n*m-k+1;
    int x=k/(2*n);
    k=k%(2*n);
    if(k<=n) cout<<2*x+1<<' '<<k;
    else cout<<2*x+2<<' '<<2*n-k+1;
    return 0;
}