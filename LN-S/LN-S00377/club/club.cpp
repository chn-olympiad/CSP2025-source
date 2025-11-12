#include<bits/stdc++.h>
#define ll long long
#define pll array<ll,4>
using namespace std;
ll n,ms;
ll a1[100005][3];
ll ch(ll x,ll y,ll z)
{
    ll mx=max(x,max(y,z));
    ll mn=min(x,min(y,z));
    ll d=x+y+z-mx-mn;
    if(d==x)return 0;
    if(d==y)return 1;
    if(d==z)return 2;
}
pll wr(ll i,ll x,ll y,ll z)
{
    ll mx=max(x,max(y,z));
    ll mn=min(x,min(y,z));
    ll mid=x+y+z-mx-mn;
    if(x==mn)return {i,1,2,0};
    if(y==mn)return {i,1,0,1};
    if(z==mn)return {i,0,1,2};
}
void dfs(ll x,ll num)
{
    if(x>n)
    {
        ms=max(ms,num);
        return;
    }
    for(ll i=0;i<3;i++)
    {
        dfs(x+1,num+a1[x][i]);
    }
    return;
}
void solve2()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<3;j++)
        {
            cin>>a1[i][j];
        }
    }

        ms=0;
        dfs(1,0);
        cout<<ms<<"\n";
    return;
}
void solve1()
{
    vector<vector<ll>>a(n+2,vector<ll>(3,0));
    vector<vector<ll>>b(n+2,vector<ll>(3,0));
    for(ll i=1;i<=n;i++)
    {
        ll mx=0;
        for(ll j=0;j<3;j++)
        {
            cin>>a[i][j];
            mx=max(mx,a[i][j]);
        }
        for(ll j=0;j<3;j++)
        {
            b[i][j]=a[i][j]-mx;
            //cout<<b[i][j]<<" ";
        }
        //cout<<"\n";
    }
    ll ans=0;
    vector<pair<ll,ll>>vis[3];
    vector<pll>vim;
    for(ll i=1;i<=n;i++)
    {
        ll dis=0;
        for(ll j=0;j<3;j++)
        {
            if(b[i][j]==0)
            {
                dis++;
            }
        }
        if(dis==1)
        {
            for(ll j=0;j<3;j++)
            {
                if(b[i][j]==0)
                {
                    ll cnt=ch(b[i][0],b[i][1],b[i][2]);
                    //cout<<cnt<<" "<<i<<endl;
                    vis[j].push_back({-1*b[i][cnt],cnt});
                    ans+=a[i][j];
                    break;
                }
            }
        }
        else
        {
            pll it=wr(i,b[i][0],b[i][1],b[i][2]);
            vim.push_back(it);
        }
    }
    //cout<<ans<<"\n";
    ll t[3];
    for(ll i=0;i<3;i++)t[i]=vis[i].size();
    for(ll i=0;i<3;i++)
    {
        if(vis[i].size()>(n/2))
        {
            sort(vis[i].begin(),vis[i].end());
            for(ll j=0;j<vis[i].size()-(n/2);j++)
            {
                ans-=vis[i][j].first;
                t[i]--;
                t[vis[i][j].second]++;
            }

        }
    }
    if(!vim.empty())
    {
        for(auto[i,x,y,z]:vim)
        {
            if(t[x]<=n/2)
            {
                ans+=b[i][x];
            }
            else if(t[y]<=n/2)
            {
                ans+=b[i][y];
            }
            else
            {
                ans+=b[i][z];
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=30)solve2();
        else solve1();
    }
    return 0;
}
