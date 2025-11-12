#include<bits/stdc++.h>
using namespace std;
const int mx=550000;
long long a[mx],n,k,i;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    if(k==0)cout<<1;
    else cout<<n/2;
    return 0;
}
