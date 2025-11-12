#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<array<int,3>> a(n+5);
    vector<vector<int>> b(3,vector<int>());
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        vector<pair<int,int>> t={{a[i][0],0},{a[i][1],1},{a[i][2],2}};
        sort(t.begin(),t.end());  
        b[t[2].second].pb(i);
        ans+=t[2].first;
    }
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    vector<bool> vis(n+5);
    for(int t=0;t<=2;t++)
    {
        int j=b[t].size();
        if(j>n/2)
        {
            for(int i:b[t])
            {
                Q.push({a[i][t]-a[i][(t+1)%3],i});
                Q.push({a[i][t]-a[i][(t+2)%3],i});
            }
            while(j>n/2)
            {
                int idx=Q.top().second,v=Q.top().first;
                Q.pop();
                if(vis[idx]) continue ;
                vis[idx]=1;
                ans-=v;
                j--;
            }
            break;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T;cin>>T;
    while(T--){solve();}
}