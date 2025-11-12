#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0,a[500005],b[500005],lr[2][500005];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    b[0]=0;
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((b[j]^b[i-1])==k)
            {
                ans++;
                i=j+1;
                j++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
