#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=998244353;
int a[N];
int sum[N],maxn[N];
int n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        maxn[i]=max(maxn[i-1],a[i]);
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n<=3)
    {
        if(sum[n]>2*maxn[n])
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    int ans=0;
    for(int l=1;l<=n;l++)
    {
        for(int len=3;len+l-1<=n;len++)
        {
            int r=l+len-1;
            int maxn=0;
            for(int i=l;i<=r;i++)
            {
                maxn=max(maxn,a[i]);
            }
            if((sum[r]-sum[l-1])>(2*maxn))
            {
                ans++;
                ans%=M;
            }
        }
    }
    cout<<(ans*2%M-1)%M;
    return 0;
}
