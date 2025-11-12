#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,m,k,fa[20005],c[15],cur[15];
int g[15][20005];
bool plan[15];
long long ans=0;
multiset<pair<int,pii> > st;
vector<pair<int,pii> > ed;

int find(int x)
{
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}

void merge(int x,int y)
{
    fa[find(x)]=find(y);
    return;
}

void solve()
{
    st.clear();
    long long sum=0;
    int num=n;
    for(auto i:ed) st.insert({i.fi,{i.se.fi,i.se.se}});
    for(int i=1;i<=k;i++)
    {
        if(plan[i])
        {
            num++;
            sum+=c[i];
            for(int j=1;j<=n;j++) st.insert({g[i][j],{num,j}});
        }
    }
    if(sum>=ans) return;
    int cnt=0;
    for(int i=1;i<=num;i++) fa[i]=i;
    while(cnt<num-1)
    {
        auto tp=(*st.begin());
        st.erase(tp);
        if(find(tp.se.fi)==find(tp.se.se)) continue;
        merge(tp.se.fi,tp.se.se);
        cnt++;
        sum+=tp.fi;
        if(sum>=ans) return;
    }
    ans=min(ans,sum);
    return;
}

int ts=0;

void dfs(int step)
{
    if(step==k+1)
    {
        if(ts) solve();
        ts++;
        //cout<<"*\n";
        return;
    }
    plan[step]=0;
    dfs(step+1);
    plan[step]=1;
    dfs(step+1);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int uu,vv,pp;
        cin>>uu>>vv>>pp;
        st.insert({pp,{uu,vv}});
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    int cnt=0;
    while(cnt<n-1)
    {
        auto tp=(*st.begin());
        st.erase(tp);
        if(find(tp.se.fi)==find(tp.se.se)) continue;
        cnt++;
        ans+=tp.fi;
        ed.push_back(tp);
        merge(tp.se.fi,tp.se.se);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}




