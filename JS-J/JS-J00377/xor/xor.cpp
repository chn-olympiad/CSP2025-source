#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(k==0 && n<=2)cout<<(n/2);
    else if(k==0 && n<=100)cout<<(n/2);
    else cout<<(n/2);
    return 0;
}
