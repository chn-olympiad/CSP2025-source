#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt,fa[20005],cc[50],sz[50],szz[20];
long long sum,s;
vector<int> c[50];
struct A
{
    int u,v,w;
}a[2000005];
bool cmp(A x,A y)
{
    return x.w<y.w;
}
int fin(int x)
{
    if(x!=fa[x])
    {
        fa[x]=fin(fa[x]);
    }
    return fa[x];
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        int xx;
        cin>>xx;
        cc[i]=xx;
        for(int j=1;j<=n;j++)
        {
            int t;
            cin>>t;
            c[i].push_back(t);
        }
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=a[i].u,v=a[i].v,w=a[i].w;
        int fu=fin(u),fv=fin(v);
        if(fu!=fv)
        {
            fa[fu]=fv;
            sum+=w;
            cnt++;

            if(cnt==n-1)
            {
                break;
            }
        }
    }


    int net=m;
    cnt=0;
    for(int i=1;i<=k;i++)
    {
        s+=cc[i];
        for(int j=0;j<n;j++)
        {
            net++;
            a[net].u=n+i;
            a[net].v=j+1;
            a[net].w=c[i][j];
        }
    }
    for(int i=1;i<=n+k;i++)
    {
        fa[i]=i;
    }
    sort(a+1,a+1+net,cmp);
    for(int i=1;i<=net;i++)
    {
        int u=a[i].u,v=a[i].v,w=a[i].w;
        int fu=fin(u),fv=fin(v);
        if(fu!=fv)
        {
            if(u>n)
            {
                sz[u-n]++;
                szz[u-n]=w;
            }
            fa[fu]=fv;
            s+=w;
            cnt++;
            if(cnt==n+k-1)
            {
                break;
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(sz[i]==1)
        {
            s-=cc[i];
            s-=szz[i];
        }
    }
    cout<<min(s,sum);
    return 0;
}
