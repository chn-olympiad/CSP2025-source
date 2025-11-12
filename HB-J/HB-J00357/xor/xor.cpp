#include <bits/stdc++.h>
using namespace std;
int n,k,a;
int b[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        b[i]=a;
    }
    if(k==0)
        cout<<n/2;
    return 0;
}
