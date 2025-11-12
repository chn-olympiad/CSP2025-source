#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500100],f[500100],g[500100],k,x[500100];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x[i]=x[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<"i:"<<i<<" ";
        g[i]=g[i-1];
        f[i]=f[i-1];
        for(int j=i;j>g[i-1];j--)
        {
          //  printf(" %d %d %d %d %d    ",i,j,x[i]^x[j],f[i-1],f[j-1]);
            if((x[i]^x[j-1])==k)
            {
                f[i]=f[j-1]+1;
                g[i]=i;
            }
        }
     //   cout<<endl;
    }
   // for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
   // for(int i=1;i<=n;i++)cout<<g[i]<<" ";cout<<endl;
    cout<<f[n];
    return 0;
}
