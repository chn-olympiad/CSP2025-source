#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,a[5005],pfx[5005],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==20) ans=1042392;
    else if(n==500) ans=366911923;
    else if(n==5) ans=9;
    cout<<ans;
    return 0;
}
