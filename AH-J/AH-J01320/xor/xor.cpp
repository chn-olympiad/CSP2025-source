#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,k,fl1,fl2,flc,pre[N],a[N],ans;
bool c[N][260];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)fl1=1;
        if(a[i]>1)fl2=1;
        if(a[i]>255)flc=1;
        pre[i]=pre[i-1]^a[i];
    }
    if(!fl1)
    {
        cout<<n/2;
    }
    else if(!fl2)
    {
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)ans++;
                else
                {
                    if(a[i-1]==1)
                    {
                        ans++;
                        a[i]=0;
                    }
                }
            }
        }
        else
        {
            for(int i=1;i<=n;i++)if(a[i]==1)ans++;
        }
        cout<<ans;
    }
    else if(!flc)
    {
        c[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<256;j++)
            {
                c[i][j]=(c[i-1][j^a[i]]);
            }
            if(c[i][k])
            {
                ans++;
                memset(c,0,sizeof(c));
            }
            c[i][0]=1;
        }
        cout<<ans;
    }
    else
    {
        long long cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>cnt;j--)
            {
                if(pre[i]^pre[j-1]==k)
                {
                    ans++;
                    cnt=i;
                    break;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
