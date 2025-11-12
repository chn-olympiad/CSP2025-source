#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,a[maxn],sum[maxn],cnt;
bool vis[maxn];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k<=1)
    {
        int cnt1=0,cnt0=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i])
                cnt1++;
            else
                cnt0++;
        }
        if(k==1)
            cout<<cnt1;
        else
            cout<<cnt0+cnt1/2;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int longth=0;longth<=n;longth++)
        for(int i=1;i<=n-longth;i++)
        {
            bool f=1;
            for(int j=i;j<=i+longth;j++)
                if(vis[j])
                {
                    f=0;
                    break;
                }
            if(!f)
                continue;
            int num=sum[i+longth]^sum[i-1];
            if(num==k)
            {
                // cout<<i<<" "<<longth<<" "<<sum[i+longth]<<" "<<sum[i-1]<<"\n";
                cnt++;
                for(int j=i;j<=i+longth;j++)
                    vis[j]=1;
            }
        }
    cout<<cnt;
    return 0;
}