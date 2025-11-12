#include <bits/stdc++.h>
using namespace std;
const long long MAXN=1e3+5;

long long s[MAXN];
long long arr[MAXN][MAXN];
long long n,k;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;

    bool flag=true;
    bool fl=true;
    long long cnt_1=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]==1) cnt_1++;
        if(s[i]!=1) flag=false;
        if(s[i]>1) fl=false;
    }

    if(flag&&k==0)
    {
        cout<<n/2;
        return 0;
    }

    if(fl)
    {
        if(k==1)
        {
            cout<<cnt_1;
            return 0;
        }
        else
        {
            long long ccr=0;
            for(long long i=1;i<=n;i++)
            {
                if(s[i]==0) ccr++;
                if(s[i]==1&&s[i+1]==1)
                {
                    ccr++;
                    i++;
                }
            }

            cout<<ccr;
            return 0;
        }
    }

    for(long long i=1;i<=n;i++)
    {
        for(long long j=i;j<=n;j++)
        {
            arr[i][j]=arr[i][j-1]^s[j];
        }
    }

    long long ans=0;
    long long i,j=n;
    for(i=n;i>=1&&j>=1;i--)
    {
        for(long long p=j;p>=i;p--)
        {
            if(arr[i][p]==k)
            {
                ans++;
                j=p-1;
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}
