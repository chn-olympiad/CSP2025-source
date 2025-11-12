#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int n,k,a[N];
int f[N],g[M];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
    memset(g,-1,sizeof(g));
    g[0]=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        if(g[a[i]^k]!=-1)f[i]=max(f[i],f[g[a[i]^k]]+1);
        g[a[i]]=i;
    }
    cout<<f[n];
    return 0;
}
