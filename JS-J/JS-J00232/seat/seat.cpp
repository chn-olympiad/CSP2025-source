#include<bits/stdc++.h>
using namespace std;
int n,m,x[110],r,a,b;
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>x[i];
    r=x[1];
    sort(x+1,x+1+n*m);
    //n*m-i+1
    int p=lower_bound(x+1,x+1+n*m,r)-x;
    p=n*m-p+1;
    a=(p+n-1)/n;
    int t=p-(a-1)*n;
    if(a%2==1)b=t;
    else b=n-t+1;
    cout<<a<<' '<<b;
    return 0;
}
