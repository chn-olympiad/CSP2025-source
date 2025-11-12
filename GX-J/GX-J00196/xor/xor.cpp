#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005],m=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) m++;
    }
    if(k==0)
    {
        if(m==0) cout<<floor(n/2);
        else cout<<m;
    }else cout<<n-m;

    return 0;
}

