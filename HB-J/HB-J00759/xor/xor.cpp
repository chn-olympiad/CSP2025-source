#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=500005;
ll a[N];
ll sum[1005][1005];


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    ll k;
    cin>>n>>k;
    ll maxn=-2e18;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn<=1)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) cnt++;
        }
        if(k==0)
        {
            int ans=0;
            for(int i=1;i<n;i++)
            {
                if(a[i]==1 && a[i+1]==1)
                {
                    ans++;
                    i++;
                }
            }
            cout<<ans+n-cnt;
        }
        else
        {
            cout<<cnt;
        }
    }
    else if(n<=1000)
    {
        for(int i=1;i<=n;i++)
        {
            sum[i][i]=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                sum[i][j]=sum[i][j-1]^a[j];
            }
        }
        ll ans=-2e18;
        for(int l=1;l<=n;l++)
        {
            int lll=l;
            int r=lll;
            long long cnt=0;
            while(lll<=n && r<=n)
            {
                if(sum[lll][r]==k)
                {
                    cnt++;
                    lll=r+1;
                    r=lll;
                }
                else r++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
