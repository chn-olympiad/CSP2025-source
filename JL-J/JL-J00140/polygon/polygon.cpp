#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxx=max(a[1],max(a[2],a[3]));
    if(n==3) {
        if(a[1]+a[2]+a[3]>maxx*2) cout<<1;
        else cout<<0;
    }
    return 0;
}
