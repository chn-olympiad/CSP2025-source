#include <bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010];
int maxx[100010],xiaohao[100010];
struct node{
    long long a,b,c;
    int maxx,xiaohao;
}abc[100010];
bool cmpa(node a,node b)
{
    if(a.xiaohao==b.xiaohao) return a.a>b.a;
    else return a.xiaohao>b.xiaohao;
}
bool cmpb(node a,node b)
{
    if(a.xiaohao==b.xiaohao) return a.b>b.b;
    else return a.xiaohao>b.xiaohao;
}
bool cmpc(node a,node b)
{
    if(a.xiaohao==b.xiaohao) return a.c>b.c;
    else return a.xiaohao>b.xiaohao;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        long long n,aa=0,bb=0,cc=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>abc[i].a>>abc[i].b>>abc[i].c;
            if(abc[i].a>=abc[i].b&&abc[i].a>=abc[i].c)
            {
                aa++;
                abc[i].maxx=1;
                abc[i].xiaohao=abc[i].a-max(abc[i].b,abc[i].c);
            }
            else if(abc[i].b>=abc[i].a&&abc[i].b>=abc[i].c)
            {
                bb++;
                abc[i].maxx=2;
                abc[i].xiaohao=abc[i].b-max(abc[i].a,abc[i].c);
            }
            else if(abc[i].c>=abc[i].a&&abc[i].c>=abc[i].b)
            {
                cc++;
                abc[i].maxx=3;
                abc[i].xiaohao=abc[i].c-max(abc[i].b,abc[i].a);
            }
        }
        if(aa<=(n/2)&&bb<=(n/2)&&cc<=(n/2))
        {
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                if(abc[i].maxx==1) ans+=abc[i].a;
                if(abc[i].maxx==2) ans+=abc[i].b;
                if(abc[i].maxx==3) ans+=abc[i].c;
            }
            cout<<ans<<endl;
            continue;
        }
        long long ans=0;
        if(aa>=bb&&aa>=cc)
        {
            int tmp=0;
            sort(abc+1,abc+n+1,cmpa);
            for(int i=1;i<=n;i++)
            {
                if(abc[i].maxx==1&&tmp<(n/2))
                {
                    ans+=abc[i].a;
                    tmp++;
                }
                else ans+=max(abc[i].b,abc[i].c);
            }
            cout<<ans<<endl;
            continue;
        }
        else if(bb>=aa&&bb>=cc)
        {
            int tmp=0;
            sort(abc+1,abc+n+1,cmpb);
            for(int i=1;i<=n;i++)
            {
                if(abc[i].maxx==2&&tmp<(n/2))
                {
                    ans+=abc[i].b;
                    tmp++;
                }
                else ans+=max(abc[i].a,abc[i].c);
            }
            cout<<ans<<endl;
            continue;
        }
        if(cc>=bb&&cc>=aa)
        {
            int tmp=0;
            sort(abc+1,abc+n+1,cmpc);
            for(int i=1;i<=n;i++)
            {
                if(abc[i].maxx==3&&tmp<(n/2))
                {
                    ans+=abc[i].c;
                    tmp++;
                }
                else ans+=max(abc[i].b,abc[i].a);
            }
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
