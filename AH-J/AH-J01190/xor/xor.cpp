#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool b[n+1],l=1;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=1)
        l=0;
    }
    if(k==0&&l==1)
    {
        cout<<n/2;
    }
    else
    {
        int a[n+1],c[n+1];
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        int sum=0;
        int wei=0,zs=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                bool num=b[i];
                for(int u=i+1;u<=j;u++)
                {
                    if((num==1&&b[u]==0)||(num==0&&b[u]==1))
                    {
                        num=1;
                    }
                    else
                    {
                        num=0;
                    }
                }
                if(num==k)
                {
                    if(i>wei)
                    {
                       zs++;
                       wei=j;
                    }
                }
            }
        }
        cout<<zs;
    }
    return 0;
}
