#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int read()
{
    int w=1,s=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n;
struct nod
{
    int x[3];
    bool operator < (const nod y) const
    {
        return max(x[1],x[2])-x[0]<max(y.x[1],y.x[2])-y.x[0];
    }
};
struct node
{
    int x[3];
    bool operator < (const node y) const
    {
        return max(max(x[1],x[2]),x[0])<max(max(y.x[1],y.x[2]),y.x[0]);
    }
}aa[N];
struct node1
{
    int x[3],id;
    bool operator < (const node1 y) const
    {
        int res1=0,res2=0;
        for(int i=0;i<=2;i++) if(i!=id) res1=max(res1,x[i]);
        for(int i=0;i<=2;i++) if(i!=y.id) res2=max(res2,y.x[i]);
        return res1-x[id]<res2-y.x[y.id];
    }
};
nod y[N];
int cnt[4];
int calc()
{
    priority_queue<nod>pq;
    cnt[0]=cnt[1]=cnt[2]=0;
    int ans=0,maxn=0;
    for(int i=1;i<=n;i++)
    {
        pq.push(y[i]);
        ans+=y[i].x[0];
    }
    cnt[0]=n,cnt[1]=0,cnt[2]=0;
    //cout<<ans<<"\n";
    while(!pq.empty())
    {
        auto u=pq.top();
        //cout<<u.x[0]<<" "<<u.x[1]<<" "<<u.x[2]<<"\n";
        pq.pop();
        int mx=max(u.x[1],u.x[2]);
        ans+=mx-u.x[0];
        //cout<<ans<<"\n";
        if(mx==u.x[1]) cnt[1]++,cnt[0]--;
        else cnt[2]++,cnt[0]--;
        if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
        {
            maxn=max(maxn,ans);
        }
    }
    return maxn;
}
int dp[2][105][105][105];
void solve1()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        int o=i&1;
        for(int a=0;a<=min(i,n/2);a++)
        {
            for(int b=0;b<=min(i,n/2);b++)
            {
                for(int c=0;c<=min(i,n/2);c++)
                {
                    if(a>=1) dp[o][a][b][c]=max(dp[o^1][a-1][b][c]+y[i].x[0],dp[o][a][b][c]);
                    if(b>=1) dp[o][a][b][c]=max(dp[o^1][a][b-1][c]+y[i].x[1],dp[o][a][b][c]);
                    if(c>=1) dp[o][a][b][c]=max(dp[o^1][a][b][c-1]+y[i].x[2],dp[o][a][b][c]);
                }
            }
        }
    }
    int ans=0;
    for(int a=0;a<=n/2;a++)
    {
        for(int b=0;b<=n/2;b++)
        {
            for(int c=0;c<=n/2;c++)
            {
                ans=max(ans,dp[n&1][a][b][c]);
            }
        }
    }
    cout<<ans<<"\n";
}
int solve2()
{
    int ans=0;
    priority_queue<node>p;
    priority_queue<node1>pq[3];
    for(int i=1;i<=n;i++) p.push(aa[i]);
    cnt[0]=cnt[1]=cnt[2]=0;
    while(!p.empty())
    {
        auto u=p.top();
        p.pop();
        int mx=-1,id=-1;
        for(int i=0;i<=2;i++) if(mx<u.x[i]) mx=u.x[i],id=i;
        node1 xx;
        for(int i=0;i<=2;i++) xx.x[i]=u.x[i];
        xx.id=id;
        if(cnt[id]<n/2)
        {
            cnt[id]++;
            pq[id].push(xx);
            ans+=mx;
        }
        else
        {
            auto y=pq[id].top();
            int res2=-1,idd=-1;
            for(int i=0;i<=2;i++) if(i!=y.id&&y.x[i]>res2&&cnt[i]<n/2) res2=y.x[i],idd=i;
            if(idd!=-1&&mx+res2-y.x[y.id]>0)
            {
                ans+=mx+res2-y.x[y.id];
                pq[id].pop();
                pq[id].push(xx);
                cnt[idd]++;
                node1 yy;
                for(int i=0;i<=2;i++) yy.x[i]=y.x[i];
                yy.id=idd;
                pq[idd].push(yy);
            }
            else
            {
                u.x[id]=-1;
                p.push(u);
            }
        }
    }
    return ans;
}
void solve()
{
    n=read();
    for(int i=1;i<=n;i++) for(int j=0;j<=2;j++) aa[i].x[j]=y[i].x[j]=read();
    if(n<=100)
    {
        solve1();
        return;
    }
    else
    {
        int ans=calc();
        for(int i=1;i<=n;i++) swap(y[i].x[0],y[i].x[1]);
        ans=max(ans,calc());
        for(int i=1;i<=n;i++) swap(y[i].x[0],y[i].x[2]);
        ans=max(ans,calc());
        ans=max(ans,solve2());
        cout<<ans<<"\n";
    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--) solve();
}
