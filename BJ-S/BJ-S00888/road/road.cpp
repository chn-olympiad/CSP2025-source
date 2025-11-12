#include <bits/stdc++.h>
using namespace std;
struct edge
{
    long long u,v,w;
}a[2273156],b[2273156];
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
long long fa[1000505],c[101],p[15][100505],ch[1000505],ans,rans=1e18;
long long find(int x)
{
    if(fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void con(int a,int b)
{
    if(ch[a]<ch[b]) fa[find(a)]=find(b),ch[b]+=ch[a];
    else fa[find(b)]=find(a),ch[a]+=ch[b];
    return ;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>p[i][j];
    }
    int upup=0;
    bool flag=1;
    for(int i=1;i<=k;i++) if(c[i]) flag=0;
    if(flag) upup=(1<<k)-1;
    for(int t=upup;t<(1<<k);t++)
    {
        ans=0;
        long long pu=t,tmp=m,s[15];
        for(int i=1;i<=m;i++) a[i].u=b[i].u,a[i].v=b[i].v,a[i].w=b[i].w;
        for(int i=k;i>=1;i--)
        {
            if(pu%2==0) s[i]=0;
            else s[i]=1;
            pu/=2;
        }
        long long tt=0;
        for(int i=1;i<=k;i++)
        {
            if(!s[i]) continue;
            ++tt;
            ans+=c[i];
            for(int j=1;j<=n;j++)
            {
                a[++tmp].u=j,a[tmp].v=n+tt;
                a[tmp].w=p[i][j];
            }
        }
        //cout<<ans<<" "<<t<<" "<<n<<endl;
        sort(a+1,a+tmp+1,cmp);
        for(int i=1;i<=n+k;i++) fa[i]=i,ch[i]=1;
        for(int i=1;i<=tmp;i++)
        {
            //cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
            if(find(a[i].u) != find(a[i].v))
            {
                con(a[i].u,a[i].v);
                ans+=a[i].w;
            }
        }
        rans=min(ans,rans);
        //cout<<ans<<endl;
        //for(int i=tmp+1;i<=m;i++) a[i].u=a[i].v=a[i].0;
    }
    cout<<rans;
}
