#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+100,M=1e7+10,K=20;
long long n,m,k,c[K],e[K][N],us[K],ans=1e18+10,f[N],sz[N];
struct Node
{
    long long frm,to,w;
}a[M];
bool cmp(Node x,Node y)
{
    return x.w<y.w;
}
void init()
{
    for(long long i=1;i<=N;i++)
    {
        f[i]=i;
        sz[i]=1;
    }
}
long long findf(long long x)
{
    if(f[x]==x)
    {
        return x;
    }
    f[x]=findf(f[x]);
    return f[x];
}
void hebing(long long x,long long y)
{
    x=findf(x);
    y=findf(y);
    if(sz[x]>sz[y])
    {
        f[y]=x;
        sz[x]+=sz[y];
    }
    else
    {
        f[x]=y;
        sz[y]+=sz[x];
    }
}
void check()
{
    long long cnt=0;
    init();
    for(long long i=1;i<=k;i++)
    {
        //cout<<us[i]<<" ";
        cnt+=c[i]*us[i];
    }
    //cout<<"\n";
    for(long long i=1;i<=m+k*n;i++)
    {
        Node now=a[i];
        if(now.frm>n)
        {
            if(!us[now.frm-n])
            {
                continue;
            }
        }
        if(findf(now.frm)!=findf(now.to))
        {
            hebing(now.frm,now.to);
            cnt+=now.w;
            if(cnt>ans) return ;
        }
    }
    ans=min(ans,cnt);
    //cout<<cnt<<'\n';
}
void dfs(long long x)
{
    /*
    //if(check()>=ans) return;
    check();
    for(int i=0;x+i<=k;i++)
    {
        us[i]=1;
        dfs(x+i+1);
        us[i]=0;
    }
    */
    if(x>k)
    {
        check();
        return;
    }
    dfs(x+1);
    us[x]=1;
    dfs(x+1);
    us[x]=0;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        a[i]=(Node){x,y,z};
    }
    for(long long i=1;i<=k;i++)
    {
        cin>>c[i];
        for(long long j=1;j<=n;j++)
        {
            cin>>e[i][j];
            a[m+(i-1)*n+j]=(Node){n+i,j,e[i][j]};
        }
    }
    sort(a+1,a+1+m+k*n,cmp);
    
    /*
    for(long long i=1;i<=m+k*n;i++)
    {
        cout<<a[i].frm<<" "<<a[i].to<<' '<<a[i].w<<"\n";
    }
    */
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}
/*

3 3 2
1 2 100
2 3 100
3 1 100
5 4 5 6
6 7 8 9




*/