#include<bits/stdc++.h>
using namespace std;
long long n,x,a[500005],sum[500005],flg[500005],s=0,sm=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],sum[i]=(sum[i-1]^a[i]);
        if(a[i]==x)
            flg[++s]=i,sm++;
    }
    flg[s+1]=n;
    for(int i=0;i<=s+1;i++)
    {
        for(int j=flg[i]+1;j<=flg[i+1]-1;j++)
        {
            for(int l=1;l<=flg[i+1]-flg[i]-1;l++)
                if((sum[j+l]^sum[j-1])==x)
                {
                    sm++;
                    j=j+l+1;
                    break;

                }


        }
    }
    cout<<sm;
    return 0;
}

