#include<bits/stdc++.h>
using namespace std;
long long sum[500005];
int a[500005];
int ans[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]^a[i];
    }
    int ans=0;
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            if((sum[r]^sum[l-1])==k)
            {
                ans=max(ans,r-l);
            }
        }
    }


        cout<<ans;
    return 0;
}
