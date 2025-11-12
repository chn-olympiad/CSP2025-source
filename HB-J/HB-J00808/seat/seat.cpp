#include <iostream>
#include <algorithm>
using namespace std;
int n,m,x,xi;
int a[110];
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    x=a[1];
    sort(a,a+n*m+1);
    for(int i=1;i<=n*m;i++)
        if(a[i]==x)
            xi=n*m-i+1;
    int l=(xi-1)/(2*n);
    xi%=2*n;
    if(xi==0)
        xi=2*n;
    if(xi<=n)
        cout<<1+l*2<<' '<<xi;
    else
        cout<<2+l*2<<' '<<2*n-xi+1;
    return 0;
}
