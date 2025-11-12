#include<bits/stdc++.h>
using namespace std;
int n, k, p, q, a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]==1) p++;
        if(a[i]==0) q++;
    }
    if(p==n)
    {
        cout<<n/2;
        return 0;
    }
    if(p+q==n)
    {
        if(k==0)
        {
            cout<<q+p/2;
        }
        else if(k==1)
        {
            cout<<q;
        }
    }
    return 0;
}
