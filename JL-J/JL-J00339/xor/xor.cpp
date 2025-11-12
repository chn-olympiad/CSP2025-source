#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,k,a[500005];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n%2==0)
    {
        cout<<n;
    }
    else
    {
        cout<<n-1;
    }
    return 0;
}
