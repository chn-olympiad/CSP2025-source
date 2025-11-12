#include<bits/stdc++.h>
using namespace std;

struct ren
{
    int a,b,c;
};

bool cmp(ren x,ren y)
{
    int tmpx=max(max(x.a,x.b),x.c)-(x.a+x.b+x.c-max(max(x.a,x.b),x.c)-min(min(x.a,x.b),x.c)),tmpy=max(max(y.a,y.b),y.c)-(y.a+y.b+y.c-max(max(y.a,y.b),y.c)-min(min(y.a,y.b),y.c));
    if (tmpx!=tmpy) return tmpx>tmpy;
    tmpx=max(max(x.a,x.b),x.c);
    tmpy=max(max(y.a,y.b),y.c);
    if (tmpx!=tmpy) return tmpx>tmpy;
    tmpx=x.a+x.b+x.c-max(max(x.a,x.b),x.c)-min(min(x.a,x.b),x.c);
    tmpy=y.a+y.b+y.c-max(max(y.a,y.b),y.c)-min(min(y.a,y.b),y.c);
    if (tmpx!=tmpy) return tmpx>tmpy;
    tmpx=min(min(x.a,x.b),x.c);
    tmpy=min(min(y.a,y.b),y.c);
    return tmpx>tmpy;
}

int n;
ren p[100005];

void xunhuan()
{
    memset(p,0,sizeof p);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i].a>>p[i].b>>p[i].c;
    }
    sort(p+1,p+n+1,cmp);
    int c1=0,c2=0,c3=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        int mx=max(max(p[i].a,p[i].b),p[i].c);
        if (mx==p[i].a)
        {
            if (c1<n/2)
            {
                ans+=mx;
                c1++;
            }
            else
            {
                if (p[i].b>p[i].c)
                {
                    ans+=p[i].b;
                    c2++;
                }
                else
                {
                    ans+=p[i].c;
                    c3++;
                }
            }
        }
        else if (mx==p[i].b)
        {
            if (c2<n/2)
            {
                ans+=mx;
                c2++;
            }
            else
            {
                if (p[i].a>p[i].c)
                {
                    ans+=p[i].a;
                    c1++;
                }
                else
                {
                    ans+=p[i].c;
                    c3++;
                }
            }
        }
        else
        {
            if (c3<n/2)
            {
                ans+=mx;
                c3++;
            }
            else
            {
                if (p[i].b>p[i].a)
                {
                    ans+=p[i].b;
                    c2++;
                }
                else
                {
                    ans+=p[i].a;
                    c1++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        xunhuan();
    }
    return 0;
}