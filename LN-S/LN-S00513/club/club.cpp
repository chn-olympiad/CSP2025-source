#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int t,n,a[100005][4],zx[100005][4],ans,kkk[100005],ansl[100005],ansll;
void dfs(int p,int res,int A,int B,int C)
{
    if(p>n)
    {
        if(ans<res)
        {
            ans=res;
        }
        return;
    }
    if(A<n/2)ansl[p]=1,dfs(p+1,res+a[p][1],A+1,B,C);
    if(B<n/2)ansl[p]=2,dfs(p+1,res+a[p][2],A,B+1,C);
    if(C<n/2)ansl[p]=3,dfs(p+1,res+a[p][3],A,B,C+1);
}
void px(ll A,ll B,ll C,ll idx)
{
    ll fir,sec,thr;
    if(A<=B)
    {
        if(B<=C)fir=3,sec=2,thr=1;
        else if(A<=C)fir=2,sec=3,thr=1;
        else fir=2,sec=1,thr=3;
    }
    else
    {
        if(A<=C)fir=3,sec=1,thr=2;
        else if(B<=C)fir=1,sec=3,thr=2;
        else fir=1,sec=2,thr=3;
    }
    zx[idx][1]=fir;zx[idx][2]=sec;zx[idx][3]=thr;
    return;
}
void solve()
{
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>T[4];
    ll cnt[4]={0,0,0,0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    ans=0;
    for(int i=1;i<=n;i++)
    {
        px(a[i][1],a[i][2],a[i][3],i);
        for(int j=1;j<=3;j++)
        {
            int flg=0;
            if(cnt[zx[i][j]]<n/2)
            {
                T[zx[i][j]].push({a[i][zx[i][j]],{i,zx[i][j]}});
                cnt[zx[i][j]]++;
                break;
            }
            else
            {
                auto p=T[zx[i][j]].top();
                ll idx=p.second.first,djzy=p.second.second,tp=1;
                while(djzy==3&&tp<n/2)
                {
                    T[zx[i][j]].pop();
                    auto qq=T[zx[i][j]].top();
                    T[zx[i][j]].push(p);
                    idx=qq.second.first,djzy=qq.second.second;
                    tp++;
                }
                if(tp==n/2)continue;
                else
                {
                    if(a[i][zx[i][j]]+(a[idx][djzy+1]-a[idx][djzy])>=0)
                    {
                        djzy++;
                        T[zx[i][j]].pop();
                        T[zx[idx][djzy]].push({a[idx][djzy],{idx,djzy}});
                        T[zx[i][j]].push({a[i][zx[i][j]],{i,zx[i][j]}});
                        break;
                    }
                }
            }
        }

    }
    for(int i=1;i<=3;i++)
    {
        while(!T[i].empty())
        {
            ans+=T[i].top().first;
            ll cut=T[i].top().second.second,cuut=T[i].top().second.first;
            T[i].pop();
        }
    }
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        int flg=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(j!=1&&a[i][j]!=0)flg=1;
            }
        }
        if(n<=10)dfs(1,0,0,0,0);
        else if(n<=200)solve();
        else if(n==100000)
        {
            if(flg)solve();
            else
            {
                for(int i=1;i<=n;i++)kkk[i]=a[i][1];
                sort(kkk+1,kkk+n+1);
                for(int i=1;i<=n/2;i++)ans+=kkk[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
