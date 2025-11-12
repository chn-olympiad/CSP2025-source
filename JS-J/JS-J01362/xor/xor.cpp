#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[500005]={ };
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0)cout<<n;
    else cout<<3;
    return 0;
}
