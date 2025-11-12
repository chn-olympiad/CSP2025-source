#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],f[500005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0)
    {
        cout<<n;
    }
    else if(k==1)
    {
        for(int i=1;i<=n-1;i++)
        {
            if(a[i]!=a[i+1]) ans++;
        }
        cout<<ans;
    }
    return 0;
}
