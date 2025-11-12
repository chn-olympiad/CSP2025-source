#include <bits/stdc++.h>
using namespace std;
struct S{
    int FS;
    bool R=false;
}a[1001];
bool cmp(S x,S y){
    if(x.FS>y.FS)return true;
    return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    a[1].R=true;
    for(int i=1;i<=n*m;i++)cin>>a[i].FS;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].R==true){
            r=i;
            break;
        }
    }
    int l=(r-1)/n;
    if(l%2==0){
        if(r%n==0)cout<<l+1<<" "<<n;
        else cout<<l+1<<" "<<r%n;
    }
    else{
        cout<<l+1<<" ";
        int c=r%n;
        if(c==0)c=n;
        cout<<n+1-c;
    }
    return 0;
}
