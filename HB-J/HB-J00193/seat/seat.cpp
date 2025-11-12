#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cnt=n*m;
    cin>>r;
    a[1]=r;
    for(int i=2;i<=cnt;i++) cin>>a[i];
    stable_sort(a+1,a+cnt+1,greater<int>());
    int xb=lower_bound(a+1,a+cnt+1,r,greater<int>())-a;
    int j=ceil(xb*1.0/n);
    if(j%2==1) cout<<j<<' '<<xb-(j-1)*n;
    if(j%2==0) cout<<j<<' '<<n-(xb-(j-1)*n)+1;
    return 0;
}
