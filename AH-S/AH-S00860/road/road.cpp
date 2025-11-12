#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
ll n,m,k,fl=1,b[15],ans,cnt,p[15],f[15][N],sum,c[N],top,num;
struct in
{
    long long x,y,z;
}a[1100005],q[1000005],s[N];
bool cnm(in u,in v)
{
    return u.z<v.z;
}
ll po(ll k)
{
    if(c[k]==k)return k;
    else return c[k]=po(c[k]);
}
void tarjan()
{
    for(int i=1;i<=n+num;i++)c[i]=i;
    if(!fl)sort(a+1,a+top+1,cnm);
    else sort(q+1,q+m+1,cnm);
    for(int i=1;i<=(fl==1?m:top);i++)
    {
        ll x,y;
        if(!fl)x=po(a[i].x),y=po(a[i].y);
        else x=po(q[i].x),y=po(q[i].y);
        if(x==y)continue;
        if(!fl)
        {
            c[x]=y;
            sum+=a[i].z;
        }
        else
        {
            c[x]=y;
            a[++top].x=q[i].x;
            a[top].y=q[i].y;
            a[top].z=q[i].z;
            s[top].x=q[i].x;
            s[top].y=q[i].y;
            s[top].z=q[i].z;
        }
        cnt++;
        if(cnt==n+num-1)break;
    }
    ans=min(ans,sum);
}
void dfs(ll u)
{
    if(u==k+1)
    {
        top=n-1;
        for(int i=1;i<=top;i++)
        {
            a[i].x=s[i].x;
            a[i].y=s[i].y;
            a[i].z=s[i].z;
        }
        for(int i=1;i<=k;i++)
        {
            if(b[i])
            {
                sum+=p[i];
                num++;
                for(int j=1;j<=n;j++)
                {
                    a[++top].x=num+n;
                    a[top].y=j;
                    a[top].z=f[i][j];
                }
            }
        }
        tarjan();
        sum=num=0;
    }
    else
    {
        dfs(u+1);
        b[u]=1;
        dfs(u+1);
        b[u]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].x>>q[i].y>>q[i].z;
    }
    tarjan();
    fl=0;
    ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=k;i++)
    {
        cin>>p[i];
        for(int j=1;j<=n;j++)
        {
            cin>>f[i][j];
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
