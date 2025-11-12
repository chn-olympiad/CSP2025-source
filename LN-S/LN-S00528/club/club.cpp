#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll ans=0;
ll a[N][4];
ll idx[N][4];
ll t;
ll n;
void dfs(ll i,ll c1,ll c2,ll c3,ll tot)
{
    if (i==n+1) return ans=max(ans,tot),void();
    if (c1==n/2)
    dfs(i+1,c1,c2+1,c3,tot+a[i][2]),
    dfs(i+1,c1,c2,c3+1,tot+a[i][3]);
    else if (c2==n/2)
    dfs(i+1,c1+1,c2,c3,tot+a[i][1]),
    dfs(i+1,c1,c2,c3+1,tot+a[i][3]);
    else if (c3==n/2)
    dfs(i+1,c1,c2+1,c3,tot+a[i][2]),
    dfs(i+1,c1+1,c2,c3,tot+a[i][1]);
    else
    dfs(i+1,c1+1,c2,c3,tot+a[i][1]),
    dfs(i+1,c1,c2+1,c3,tot+a[i][2]),
    dfs(i+1,c1,c2,c3+1,tot+a[i][3]);
}
vector<int> buc[4];
int nx(int x)
{
    if (x==3) return 1;
    return x+1;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (ll i=1;i<=n;i++)
        for (ll j=1;j<=3;j++)
        cin>>a[i][j],idx[i][j]=j;
        if (n<=10)
        {
            ans=0;
            dfs(1,0,0,0,0);
            cout<<ans<<"\n";
        }
        else
        {
            ll ans=0;
            for (ll i=1;i<=n;i++)
            sort(idx[i]+1,idx[i]+3,[&](int x,int y){return a[i][x]>a[i][y];});
            for (ll i=1;i<=n;i++) buc[idx[i][1]].push_back(i),ans+=a[i][idx[i][1]];
            if (buc[1].size()<=n/2&&buc[2].size()<=n/2&&buc[3].size()<=n/2)
            {
                cout<<ans<<"\n";
            }
            else
            {
                vector<int> vv;
                for (ll i=1;i<=3;i++)
                {
                    if (buc[i].size()>n/2)
                    {
                        for (ll x:buc[i]) vv.push_back(a[x][idx[x][1]]-a[x][idx[x][2]]);
                        sort(vv.begin(),vv.end());
                        for (int j=0;j<buc[i].size()-n/2;j++) ans-=vv[j];
                        cout<<ans<<"\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}