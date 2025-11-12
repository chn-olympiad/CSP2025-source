/*
lg 592080 关注谢谢喵！

15:43 开始写题
16:33 
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
// #define MORE_TEST
using namespace std;
const string FILE_NAME="road";
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
        freopen((FILE_NAME+".in").c_str(),"r",stdin);
        freopen((FILE_NAME+".out").c_str(),"w",stdout);
    #endif

    int T=1;
    #ifdef MORE_TEST
        cin>>T;
    #endif

    while (T--)
    {
        int n,m,k;
        cin>>n>>m>>k;

        vector<vector<pair<int,int>>> edge(n+1);
        for (int i=1;i<=m;i++)
        {
            int x,y,d;
            cin>>x>>y>>d;
            edge[x].emplace_back(y,d);
            edge[y].emplace_back(x,d);
        }

        vector<int> a(k+1);
        vector<vector<int>> v(k+1,vector<int>(n+1));
        bool flag=1;
        for (int i=1;i<=k;i++)
        {
            cin>>a[i];
            flag&=(a[i]==0);
            for (int j=1;j<=n;j++)
                cin>>v[i][j],flag&=(v[i][j]==0);
        }
        if (flag)
        {
            cout<<"0\n";
            break;
        }
        
        int mx=(1<<k)-1,ans=0x3f3f3f3f3f3f3f3f;

        __gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>,__gnu_pbds::rc_binomial_heap_tag> q;
        vector<int> dis(n+k+1,0x3f3f3f3f3f3f3f3f);
        bitset<10011> vis;

        for (int i=0;i<=mx;i++)
        {
            int res=0;

            for (int j=1;j<=k;j++)
                if (i>>(j-1)&1)
                    res+=a[j];
            
            fill(dis.begin(),dis.end(),0x3f3f3f3f3f3f3f3f);
            vis.reset();
            q.push({0,1});
            dis[1]=0;

            while (!q.empty())
            {
                auto t=q.top();
                q.pop();
                if (vis[t.second])
                    continue;
                vis[t.second]=1;
                res+=t.first;

                if (t.second<=n)
                {
                    for (auto x:edge[t.second])
                        if (!vis[x.first]&&dis[x.first]>x.second)
                            dis[x.first]=x.second,q.push({x.second,x.first});
                    for (int j=1;j<=k;j++)
                        if (!vis[n+j]&&(i>>(j-1)&1)&&dis[n+j]>v[j][t.second])
                            dis[n+j]=v[j][t.second],q.push({v[j][t.second],n+j});
                }
                else
                {
                    for (int j=1;j<=n;j++)
                        if (!vis[j]&&dis[j]>v[t.second-n][j])
                            dis[j]=v[t.second-n][j],q.push({v[t.second-n][j],j});
                }
            }
            ans=min(ans,res);
        }
        cout<<ans<<'\n';
    }

    return 0;
}