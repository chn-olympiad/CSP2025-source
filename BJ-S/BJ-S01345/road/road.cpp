#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int u,v,w;
    friend bool operator<(node x,node y)
    {
        return x.w<y.w;
    }
}a[2000010];
int b[20][10010],fa[200010],c[15],n,m,k;
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
void init(int cur)
{
    for (int i=1;i<=cur;i++) fa[i]=i;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >>n>>m>>k;
    //for (int i=1;i<=3*m;i++);
    //cout<<clock()<<endl;
    for (int i=1;i<=m;i++) cin >>a[i].u>>a[i].v>>a[i].w;
    //cout<<clock()<<endl;
    for (int i=1;i<=k;i++)
    {
        cin >>c[i];
        for (int j=1;j<=n;j++) cin >>b[i][j];
    }
    //cout<<clock()<<endl;
    if(k==0)
    {
        sort(a+1,a+m+1);
        init(n);
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            if(find(a[i].u)!=find(a[i].v))
            {
                ans+=a[i].w;
                merge(a[i].u,a[i].v);
            }
        }
        cout<<ans;
        return 0;
    }
    if(k<=5)
    {
        int minn=1e18;
        for (int s=0;s<(1<<k);s++)
        {
            int cur=m,cur1=n;
            int ans=0;
            for (int i=1;i<=k;i++)
            {
                if(s/(1<<i-1)%2)
                {
                    cur1++;
                    ans+=c[i];
                    for (int j=1;j<=n;j++)
                    {
                        a[++cur].u=cur1;
                        a[cur].v=j;
                        a[cur].w=b[i][j];
                    }
                }
            }
            init(cur1);
            sort(a+1,a+cur+1);
            for (int i=1;i<=cur;i++)
            {
                if(find(a[i].u)!=find(a[i].v))
                {
                    ans+=a[i].w;
                    merge(a[i].u,a[i].v);
                }
            }
            minn=min(minn,ans);
        }
        cout<<minn;
        return 0;
    }
    int ans=0,cur=m,cur1=n;
    for (int i=1;i<=k;i++)
    {
        ans+=c[i];
        cur1++;
        for (int j=1;j<=n;j++)
        {
            a[++cur]={cur1,j,b[i][j]};
        }
    }
    //cout<<clock()<<" "<<cur<<" "<<cur1<<endl;
    sort(a+1,a+cur+1);
    init(cur1);
    for (int i=1;i<=cur;i++)
    {
        if(find(a[i].u)!=find(a[i].v))
        {
            ans+=a[i].w;
            merge(a[i].u,a[i].v);
        }
    }
    cout<<ans;
    return 0;
}
