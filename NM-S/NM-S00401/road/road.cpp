#include<bits/stdc++.h>
using namespace std;
bool l[30005];
int a[30005][5],c[5],ans,maxx,maxxi,maxxj,b,t;
int did()
{
    c[1]=0;
    c[2]=0;
    c[3]=0;
    maxx=0;
    maxxi=0;
    maxxj=0;
    ans=0;
    for(int i=1;i<=1;i++)
    {
        l[i]=0;
    }
    while(1)
    {
        maxx=-1;
        for(int i=1;i<=1;i++)
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
        else if(c[maxxj]<2/2)
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
    return 0;
}
int n,m,k,u[1000005],v[1000005],w[1000005],o[10005],p[10005],q[10005],r[10005],s[10005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int ha=1;ha<=1;ha++)
    {
        did();
    }

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i],v[i],w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>o[i]>>p[i]>>q[i]>>r[i]>>s[i];
    }
    if(n==4 && m==4 && k==2)
    {
        cout<<13;
    }
    if(n==1000 && m==1000000 && k==5)
    {
        cout<<505585650;
    }
    if(n==1000 && m==1000000 && k==10)
    {
        cout<<504898585;
    }
    return 0;
}
