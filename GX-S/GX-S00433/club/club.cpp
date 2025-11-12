#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define endll " "
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) x&-x
#define it inline int
#define iv inline void
#define ib inline bool
using namespace std;
const int MAXN=500050;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
it gcd(int x,int y) {return y==0?x:gcd(y,x%y);}
it lcm(int x,int y) {return x/gcd(x,y)*y;}
it max(int x,int y) {return x>y?x:y;}
it min(int x,int y) {return x<y?x:y;}
it ksm(int x,int m,int mod)
{
    int res=1,bas=x%mod;
    while(m)
    {
        if(m&1)
            res=(res*bas)%mod;
        bas=(bas*bas)%mod;
        m >>= 1;
    }
    return res;
}
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int n,m,l,r,u,v,w,cnt,tot,ans,head[MAXN],T,a[MAXN][4],tl[MAXN],cnt1,cnt2,cnt3;//need dp
bool flag1,vis[MAXN],flag2,flag3;
int dp[MAXN][4][2];
struct lane
{
    int a,b,c,maxn,pos;
}t[MAXN];
struct node
{
    int val,id;
}dj[MAXN],fj[MAXN];
ib cmp1(lane x,lane y)
{
    return x.maxn>y.maxn;
}
ib cmp2(node x,node y)
{
    return x.val>y.val;
}
iv A_1()
{
    for(int i=1;i<=n;i++)
        tl[i]=t[i].a;
    sort(tl+1,tl+n+1);
    for(int i=n;i>n/2;i--)
        ans+=tl[i];
    cout<<ans<<endl;
}
iv A_2()
{
    for(int i=1;i<=n;i++)
        tl[i]=t[i].b;
    sort(tl+1,tl+n+1);
    for(int i=n;i>n/2;i--)
        ans+=tl[i];
    cout<<ans<<endl;
}
iv A_3()
{
    for(int i=1;i<=n;i++)
        tl[i]=t[i].c;
    sort(tl+1,tl+n+1);
    for(int i=n;i>n/2;i--)
        ans+=tl[i];
    cout<<ans<<endl;
}
iv B()
{
    ans=max(ans,t[1].a+t[2].b);
    ans=max(ans,t[1].a+t[2].c);
    ans=max(ans,t[1].b+t[2].a);
    ans=max(ans,t[1].b+t[2].c);
    ans=max(ans,t[1].c+t[2].a);
    ans=max(ans,t[1].c+t[2].b);
    cout<<ans<<endl;
}
iv solve()
{
    sort(t+1,t+n+1,cmp1);
    for(int i=1;i<=n;i++)
    {
        if(t[i].pos==1)
        {
            if(cnt1>=n/2)
            {
                if(t[i].b>=t[i].c && cnt2<n/2)
                {
                    ans+=t[i].b;
                    cnt2++;
                }
                else
                {
                    if(t[i].c>=t[i].b && cnt3<n/2)
                    {
                        ans+=t[i].c;
                        cnt3++;
                    }
                }
            }
            else
            {
                ans+=t[i].a;
                cnt1++;
            }
        }//------------------------------------------
        if(t[i].pos==2)
        {
            if(cnt2>=n/2)
            {
                if(t[i].a>=t[i].c && cnt1<n/2)
                {
                    ans+=t[i].a;
                    cnt1++;
                }
                else
                {
                    if(t[i].c>=t[i].a && cnt3<n/2)
                    {
                        ans+=t[i].c;
                        cnt3++;
                    }
                }
            }
            else
            {
                ans+=t[i].b;
                cnt2++;
            }
        }//-----------------------------------------
        if(t[i].pos==3)
        {
            if(cnt3>=n/2)
            {
                if(t[i].b>=t[i].a && cnt2<n/2)
                {
                    ans+=t[i].b;
                    cnt2++;
                }
                else
                {
                    if(t[i].a>=t[i].b && cnt1<n/2)
                    {
                        ans+=t[i].a;
                        cnt1++;
                    }
                }
            }
            else
            {
                ans+=t[i].c;
                cnt3++;
            }
        }
    }
    cout<<ans<<endl;
}
iv Final_verdict()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        dj[i].id=fj[i].id=i;
        dj[i].val=t[i].a;
        fj[i].val=t[i].b;
    }
    sort(dj+1,dj+n+1,cmp2);
    sort(fj+1,fj+n+1,cmp2);
    for(int i=1;i<=n;i++)
    {
        if(cnt1==n/2 || cnt2==n/2)
            break;
        if(dj[i].val>=fj[cnt].val && !vis[dj[i].id])
        {
            ans+=dj[i].val;
            vis[dj[i].id]=1;
            cnt1++;
            if(dj[i].id==fj[cnt].id)
                cnt++;
        }
        if(dj[i].val<dj[cnt].val && !vis[dj[cnt].id])
        {
            ans+=dj[cnt].val;
            vis[dj[cnt].id]=1;
            cnt++;
            cnt2++;
        }
    }
    if(cnt1+cnt2!=n)
    {
        if(cnt1==n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(!vis[fj[i].id])
                {
                    vis[fj[i].id]=1;
                    ans+=fj[i].val;
                }
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(!vis[dj[i].id])
                {
                    vis[dj[i].id]=1;
                    ans+=dj[i].val;
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    fre("club");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        flag1=flag2=flag3=0;
        cnt1=cnt2=cnt3=0;
        ans=0;
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            cin >> t[i].a >> t[i].b >> t[i].c;
            if(t[i].a>0)
                flag1=1;
            if(t[i].b>0)
                flag2=1;
            if(t[i].c>0)
                flag3=1;
            t[i].maxn=max(t[i].a,max(t[i].b,t[i].c));
            if(t[i].a==t[i].maxn)
                t[i].pos=1;
            if(t[i].b==t[i].maxn)
                t[i].pos=2;
            if(t[i].c==t[i].maxn)
                t[i].pos=3;
        }
        if(!flag1 || !flag2)
        {
            if(flag1)
                A_1();
            if(flag2)
                A_2();
        }
        else
        {
            if(n==2)
                B();
            else
            {
                if(flag1==1&&flag2==1&&flag3==0)
                    Final_verdict();
                else
                    solve();
            }
        }
    }
    return 0;
}
