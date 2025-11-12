#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,a[N],x,p;
bool cmp(const int &x,const int &y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==x) p=i;
    int x=ceil(p*1.0/m);
    int y=(p-1)%m;
    if(x%2!=0) cout<<x<<" "<<y+1;
    else cout<<x<<" "<<n-y;
    return 0;
}
