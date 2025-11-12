#include <bits/stdc++.h>
using namespace std;
int p[5010]={0};
int panduan(int mx,int i,int j)
{
    if(mx<(i+j+mx))
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }


        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int maxn=0;
                for(int k=j+1;k<=n;k++)
                {
                    if(p[i]>p[j])
                    {
                        if(p[i]>p[k])
                        {
                            maxn+=panduan(i,j,k);
                        }
                        else
                        {
                            maxn+=panduan(k,j,i);
                        }
                    }
                    else
                    {
                        if(p[j]>p[k])
                        {
                            maxn+=panduan(j,k,i);
                        }
                        else
                        {
                            maxn+=panduan(k,j,i);
                        }
                    }
                }
                ans=max(ans,maxn);
            }
        }
        cout<<ans<<endl;

    return 0;
}
