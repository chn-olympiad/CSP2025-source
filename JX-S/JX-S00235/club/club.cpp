#include <bits/stdc++.h>
using namespace std;
int t,n;
struct Edge
{
    int id;
    int w;
};
bool cmp(Edge a,Edge b)
{
    return a.w>b.w;
}
int maxx(Edge a,Edge b,Edge c)
{
    if(a.w>b.w)
    {
        if(a.w>c.w)
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    else
    {
        if(b.w>c.w)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}
bool f[100037];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int p=1;p<=t;p++)
    {
        int ans=0;
        vector<Edge>a;
        vector<Edge>b;
        vector<Edge>c;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            f[i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a.push_back((Edge){i,x});
            b.push_back((Edge){i,y});
            c.push_back((Edge){i,z});
        }
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end(),cmp);
        sort(c.begin(),c.end(),cmp);
        int la=0,lb=0,lc=0,sa=0,sb=0,sc=0;
        for(int i=1;i<=n;i++)
        {
            while(f[a[la].id])la++;
            while(f[b[lb].id])lb++;
            while(f[c[lc].id])lc++;
            if(maxx(a[la],b[lb],c[lc])==1)
            {
                if(sa==n/2)
                {
                    if(b[lb].w>c[lc].w )
                    {
                        ans+=b[lb].w;
                        f[b[lb++].id]=true;
                        sb++;
                    }
                    else
                    {
                        ans+=c[lc].w;
                        f[c[lc++].id]=true;
                        sc++;
                    }
                }
                else
                {
                    ans+=a[la].w;
                    f[a[la++].id]=true;
                    sa++;
                }
            }
            else if(maxx(a[la],b[lb],c[lc])==2)
            {
                if(sb==n/2)
                {
                    if(a[la].w>c[lc].w )
                    {
                        ans+=a[la].w;
                        f[a[la++].id]=true;
                        sa++;
                    }
                    else
                    {
                        ans+=c[lc].w;
                        f[c[lc++].id]=true;
                        sc++;
                    }
                }
                else
                {
                    ans+=b[lb].w;
                    f[b[lb++].id]=true;
                    sb++;
                }
            }
            else
            {
                if(sc==n/2)
                {
                    if(b[lb].w>a[la].w )
                    {
                        ans+=b[lb].w;
                        f[b[lb++].id]=true;
                        sb++;
                    }
                    else
                    {
                        ans+=a[la].w;
                        f[a[la++].id]=true;
                        sa++;
                    }
                }
                else
                {
                    ans+=c[lc].w;
                    f[c[lc++].id]=true;
                    sc++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
