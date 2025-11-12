#include<bits/stdc++.h>
using namespace std;
struct node
{
    int be,en,val;
    bool operator<(const node n)const
    {
        return n.val<val;
    }
}tmp;
int n,m,k,fa[10010],a[20][10010],mp[1010][1010],ans=0;
priority_queue<node> s;
int find(int x)
{
    if(fa[x]==x)
        return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void solve()
{
    int i,j,fx,fy,cnt=0;
//    for(it=s.begin(); it!=s.end(); it++)
//        cout<<it->be<<' '<<it->en<<' '<<it->val<<'\n';
    for(i=1; i<=n; ++i)
        fa[i]=i;
    while(!s.empty())
    {
        tmp=s.top();
        s.pop();
        fx=find(tmp.be);
        fy=find(tmp.en);
        if(fx!=fy)
        {
            fa[fx]=fy;
            ans=ans+tmp.val;
            cnt++;
        }
        if(cnt==n-1)
            break;
    }
    cout<<ans;
    return;
}
void solve1()
{
    int i,jx,jy;
    for(jx=1; jx<=n; ++jx)
    {
        for(jy=1; jy<=n; ++jy)
            mp[jx][jy]=0x7777ffff;
    }
    for(i=1; i<=k; ++i)
    {
        if(a[i][0]!=0)
            return;
        for(jx=1; jx<=n; ++jx)
        {
            for(jy=jx+1; jy<=n; ++jy)
                mp[jx][jy]=min(mp[jx][jy],a[i][0]+a[i][jx]+a[i][jy]);
        }
    }
    for(jx=1; jx<=n; ++jx)
    {
        for(jy=jx+1; jy<=n; ++jy)
        {
            tmp.be=jx;
            tmp.en=jy;
            tmp.val=mp[jx][jy];
            s.push(tmp);
        }
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j;
    cin>>n>>m>>k;
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&tmp.be,&tmp.en,&tmp.val);
        s.push(tmp);
    }
    for(i=1; i<=k; i++)
    {
        for(j=0; j<=n; j++)
            scanf("%d",&a[i][j]);
    }
    if(k>0 && n<=1000)
        solve1();
    solve();
    return 0;
}
