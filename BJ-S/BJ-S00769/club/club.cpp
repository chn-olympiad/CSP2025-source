#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,maxn;
}p[1000010];
bool cmp(node x,node y)
{
    return x.maxn<y.maxn;
}
bool ccmp(node x,node y)
{
    return x.maxn>y.maxn;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].a>>p[i].b>>p[i].c;
            p[i].maxn=max(p[i].a,max(p[i].b,p[i].c));
        }
        sort(p+1,p+n+1,cmp);
        int sa=0,sb=0,sc=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i].maxn==p[i].a)
            {
                if(sa<n/2)
                {
                    sa++;
                    ans+=p[i].maxn;
                }
                else if(p[i].b>p[i].c)
                {
                    if(sb<n/2)
                    {
                        sb++;
                        ans+=p[i].b;
                    }
                    else
                    {
                        sc++;
                        ans+=p[i].c;
                    }
                }
                else
                {
                    if(sc<n/2)
                    {
                        sc++;
                        ans+=p[i].c;
                    }
                    else
                    {
                        sb++;
                        ans+=p[i].b;
                    }
                }
            }
            else if(p[i].maxn==p[i].b)
            {
                if(sb<n/2)
                {
                    sb++;
                    ans+=p[i].maxn;
                }
                else if(p[i].a>p[i].c)
                {
                    if(sa<n/2)
                    {
                        sa++;
                        ans+=p[i].a;
                    }
                    else
                    {
                        sc++;
                        ans+=p[i].c;
                    }
                }
                else
                {
                    if(sc<n/2)
                    {
                        sc++;
                        ans+=p[i].c;
                    }
                    else
                    {
                        sa++;
                        ans+=p[i].a;
                    }
                }
            }
            else
            {
                if(sc<n/2)
                {
                    sc++;
                    ans+=p[i].maxn;
                }
                else if(p[i].a>p[i].b)
                {
                    if(sa<n/2)
                    {
                        sa++;
                        ans+=p[i].a;
                    }
                    else
                    {
                        sb++;
                        ans+=p[i].b;
                    }
                }
                else
                {
                    if(sb<n/2)
                    {
                        sb++;
                        ans+=p[i].b;
                    }
                    else
                    {
                        sa++;
                        ans+=p[i].a;
                    }
                }
            }
        }
        sort(p+1,p+n+1,ccmp);
        sa=0;sb=0;sc=0;
        long long aans=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i].maxn==p[i].a)
            {
                if(sa<n/2)
                {
                    sa++;
                    aans+=p[i].maxn;
                }
                else if(p[i].b>p[i].c)
                {
                    if(sb<n/2)
                    {
                        sb++;
                        aans+=p[i].b;
                    }
                    else
                    {
                        sc++;
                        aans+=p[i].c;
                    }
                }
                else
                {
                    if(sc<n/2)
                    {
                        sc++;
                        aans+=p[i].c;
                    }
                    else
                    {
                        sb++;
                        aans+=p[i].b;
                    }
                }
            }
            else if(p[i].maxn==p[i].b)
            {
                if(sb<n/2)
                {
                    sb++;
                    aans+=p[i].maxn;
                }
                else if(p[i].a>p[i].c)
                {
                    if(sa<n/2)
                    {
                        sa++;
                        aans+=p[i].a;
                    }
                    else
                    {
                        sc++;
                        aans+=p[i].c;
                    }
                }
                else
                {
                    if(sc<n/2)
                    {
                        sc++;
                        aans+=p[i].c;
                    }
                    else
                    {
                        sa++;
                        aans+=p[i].a;
                    }
                }
            }
            else
            {
                if(sc<n/2)
                {
                    sc++;
                    aans+=p[i].maxn;
                }
                else if(p[i].a>p[i].b)
                {
                    if(sa<n/2)
                    {
                        sa++;
                        aans+=p[i].a;
                    }
                    else
                    {
                        sb++;
                        aans+=p[i].b;
                    }
                }
                else
                {
                    if(sb<n/2)
                    {
                        sb++;
                        aans+=p[i].b;
                    }
                    else
                    {
                        sa++;
                        aans+=p[i].a;
                    }
                }
            }
        }
        cout<<max(ans,aans);
    }
}
