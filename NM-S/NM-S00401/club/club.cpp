#include<bits/stdc++.h>
using namespace std;
bool l[30005];
int a[30005][5],c[5],ans,maxx,maxxi,maxxj,n,t;
int did()
{
    c[1]=0;
    c[2]=0;
    c[3]=0;
    maxx=0;
    maxxi=0;
    maxxj=0;
    n=0;
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        l[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    while(1)
    {
        maxx=-1;
        for(int i=1;i<=n;i++)
        {
            if(l[i]==1)
            {
                continue;
            }
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]>=maxx)
                {
                    maxx=a[i][j];
                    maxxi=i,maxxj=j;
                }
            }
        }
        if(maxx==-1)
        {
            break;
        }
        else if(c[maxxj]<n/2)
        {
            c[maxxj]++;
            ans+=a[maxxi][maxxj];
            l[maxxi]=1;
            a[maxxi][1]=-1;
            a[maxxi][2]=-1;
            a[maxxi][3]=-1;
        }
        else
        {
            a[maxxi][maxxj]=-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int ha=1;ha<=t;ha++)
    {
        did();
    }
    return 0;
}
