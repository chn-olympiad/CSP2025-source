#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
const int N=1e5+10;
int n,a[N][3],vis[N];
int solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin>>a[i][j];
    int cnt[3]={0,0,0},ans=0;
    for(int i=1;i<=n;i++)
    {
        int w=max({a[i][0],a[i][1],a[i][2]});
        ans+=w;
        if(w==a[i][0]) cnt[0]++,vis[i]=0;
        else if(w==a[i][1]) cnt[1]++,vis[i]=1;
        else cnt[2]++,vis[i]=2;
    }
    if(max({cnt[0],cnt[1],cnt[2]})<=n/2) return ans;
    if(cnt[1]>n/2)
    {
        for(int i=1;i<=n;i++) swap(a[i][0],a[i][1]);
        for(int i=1;i<=n;i++) 
        {
            if(vis[i]==0) vis[i]=1;
            else if(vis[i]==1) vis[i]=0;
        }
        swap(cnt[0],cnt[1]);
    }
    else 
    {
        if(cnt[2]>n/2)
        {
            for(int i=1;i<=n;i++) swap(a[i][0],a[i][2]);
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0) vis[i]=2;
                else if(vis[i]==2) vis[i]=0;
            }
            swap(cnt[0],cnt[2]);
        }
    }
    int op=cnt[0]-n/2;
    vector<int> s;
    for(int i=1;i<=n;i++) if(vis[i]==0) s.pb(a[i][0]-max(a[i][1],a[i][2]));
    sort(all(s));
    for(int i=0;i<op;i++) ans-=s[i];
    return ans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) cout<<solve()<<'\n';
    return 0;
}