#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
const int N=1e4+50;
const int M=2e6+50;
const int K=15;
int fa[N],c[K];
inline int find(int x)
{
    if(x==fa[x])    return x;
    return fa[x]=find(fa[x]);
}
struct edge
{
    int u,v,w;
}e[M],e2[M],e3[M];
bool cmp(edge x,edge y)
{
    if(x.w!=y.w)
        return x.w<y.w;
    if(x.u!=y.u)
        return x.u<y.u;
    return x.v<y.v;
}
struct node
{
    int u,d;
    bool operator<(const node&x)    const
    {
        return d>x.d;
    }
};
void read(int &x)
{
    int d=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        d=d*10+ch-'0';
        ch=getchar();
    }
    x=d*f;
}
void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
bool vis[N],del[M];
int n,m,k,a[K][N];
ll ans;
//vector<int> E[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n); read(m); read(k);
    for(int i=1;i<=m;i++)
    {
        read(e[i].u);
        read(e[i].v);
        if(e[i].u>e[i].v)   swap(e[i].u,e[i].v);
        read(e[i].w);
        e2[i]=e[i];
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<m;i++)
    {
        if(e[i].u==e[i+1].u&&e[i].v==e[i+1].v)  del[i+1]=1;
    }
    int m2=0;
    for(int i=1;i<=m;i++)
    {
        if(!del[i]) e2[++m2]=e[i];
    }
    m=m2;
    for(int i=1;i<=m;i++)   e[i]=e2[i];
    int A=1;
    for(int i=1;i<=k;i++)
    {
        read(c[i]);
        if(c[i])    A=0;
        int ok=0;
        for(int j=1;j<=n;j++)
        {
            read(a[i][j]);
            if(!a[i][j])    ok=1;
        }
        A|=ok;
    }
    //cout<<m<<'\n';
    ans=inf;
    if(A)
    {
        int ntot=n,etot=m;
        for(int id=1;id<=k;id++)
        {
            ++ntot;
            for(int i=1;i<=n;i++)
            {
                e[++etot].u=ntot;
                e[etot].v=i;
                e[etot].w=a[id][i];
            }
        }
        for(int i=1;i<=ntot;i++)    fa[i]=i;
        sort(e+1,e+etot+1,cmp);
        ll sum=0;
        for(int i=1;i<=etot;i++)
        {
            int rx=find(e[i].u),ry=find(e[i].v);
            if(rx!=ry)
            {
                sum+=e[i].w;
                fa[rx]=ry;
            }
        }
        write(sum);
        return 0;
    }
    sort(e2+1,e2+m+1,cmp);
    for(int x=0;x<(1<<k);x++)
    {
        int g=x,etot=0,et=0,ntot=n;
        //for(int j=1;j<=m;j++)   e[j]=e2[j];
        int id=1;
        ll sum=0;
        while(g)
        {
            if(g&1)
            {
                sum+=c[id];
                ++ntot;
                for(int i=1;i<=n;i++)
                {
                    e3[++et].u=ntot;
                    e3[et].v=i;
                    e3[et].w=a[id][i];
                }
            }
            id++;
            g>>=1;
        }
        if(sum>ans) break;
        sort(e3+1,e3+et+1,cmp);
        for(int i=1;i<=ntot;i++)    fa[i]=i;
        int id1=1,id2=1;
        while(id1<=m||id2<=et)
        {
            if(id1>m)   e[++etot]=e3[id2++];
            else if(id2>et) e[++etot]=e2[id1++];
            else
            {
                if(e2[id1].w<e3[id2].w)  e[++etot]=e2[id1++];
                else    e[++etot]=e3[id2++];
            }
        }
        //sort(e+1,e+etot+1,cmp);
        for(int i=1;i<=etot;i++)
        {
            int rx=find(e[i].u),ry=find(e[i].v);
            if(rx!=ry)
            {
                sum+=e[i].w;
                if(sum>ans) break;
                fa[rx]=ry;
            }
        }
        ans=min(ans,sum);
        /*
        for(int i=1;i<=ntot;i++)    fa[i]=i;
        q.push(1);
        while(!q.empty())
        {
            node u=
        }
        ans=min(ans,sum);
        */
    }
    write(ans);
    return 0;
}
