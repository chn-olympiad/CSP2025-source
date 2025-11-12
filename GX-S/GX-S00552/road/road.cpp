#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
    while(48<=ch&&ch<=57){x=(x*10)+(ch^48);ch=getchar();}
    return x*f;
}

const int N=1e6+10;

int n,m,k;

ll cost[200];

struct edge{
    ll x,y,w;
    int id;
};

std::vector<edge> v,temp,v2[20];

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

struct DSU{

    int fa[N];

    void init(int x)
    {
        for(int i=1;i<=x;i++)
            fa[i]=i;
    }

    int find(int x)
    {
        return (fa[x]==x)?x:fa[x]=find(fa[x]);
    }

    void merge(int x,int y)
    {
        x=find(x),y=find(y);

        if(x==y)
            return;

        fa[x]=y;
    }

}D;

ll Kruskal()
{
    D.init(n+100);

    ll ret=0;

    for(auto p:v)
    {
        int x=p.x,y=p.y;

        x=D.find(x),y=D.find(y);

        if(x==y)
            continue;

        ret+=p.w;
        D.merge(x,y);
    }

    return ret;
}


namespace solveE{

    void solve()
    {
        ll ans=1ll<<60;
        temp=v;

        for(int s=0;s<(1<<k);s++)
        {
            ll ret=0;

            v=temp;

            for(int j=0;j<k;j++)
                if((s>>j)&1)
                {
                    ret+=cost[j+1];

                    for(auto p:v2[j+1])
                        v.push_back(p);
                }

            std::sort(v.begin(),v.end(),cmp);

            ret+=Kruskal();

            if(ret<ans)
                ans=ret;
        }

        printf("%lld\n",ans);
    }
}

namespace solveA
{
    void solve()
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
                v.push_back(v2[i][j-1]);
        }

        std::sort(v.begin(),v.end(),cmp);

        ll ans=Kruskal();

        printf("%lld\n",ans);
    }
}

void solve()
{
    std::sort(v.begin(),v.end(),cmp);
    temp=v;

    ll ans=Kruskal(),sum=0;

    for(int i=1;i<=k;i++)
    {
        ll ret=cost[i]+sum;

        v.clear();

        int j=0,l=0;

        for(;j<(int)temp.size();j++)
        {
            while(l<(int)v2[i].size()&&v2[i][l].w<temp[j].w)
                v.push_back(v2[i][l]),l++;

            v.push_back(temp[j]);
        }

        for(;l<(int)v2[i].size();l++)
            v.push_back(v2[i][l]);

        ret+=Kruskal();

        if(ret<=ans)
        {
            ans=ret,temp=v,sum+=cost[i];
            continue;
        }
    }

    printf("%lld\n",ans);

}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=read(),m=read(),k=read();

    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();ll w=read();
        v.push_back({x,y,w,0});
    }

    bool flag=true;

    for(int i=1;i<=k;i++)
    {
        cost[i]=read();

        bool f=0;

        for(int j=1;j<=n;j++)
        {
            ll w=read();
            v2[i].push_back({n+i,j,w,i});

            if(!w)
                f=1;
        }

        std::sort(v2[i].begin(),v2[i].end(),cmp);

        f&=(cost[i]==0);
        flag&=f;
    }

    if(flag)
    {
        solveA::solve();
        return 0;
    }

    if(k==0||(k<=5&&m<=100010))
        solveE::solve();
    else
        solve();

    return 0;
}

/*
4 3 2
1 2 3
2 3 7
3 4 8
3 1 9 9 9
3 2 9 2 9
*/

