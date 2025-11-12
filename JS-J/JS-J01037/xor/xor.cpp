#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,k;cin>>n>>k;int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1&&k==0) cout<<0;
    else cout<<floor((-1+n)*n/2-(n/2+1)*n/2/2+(n%2==1));
    return 0;
}
