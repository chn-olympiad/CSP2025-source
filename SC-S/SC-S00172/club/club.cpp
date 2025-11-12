#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct p
{
    int u,t;
    long long w;
    bool operator < (const p &rhs)const
    {
        return w < rhs.w;
    }
};
priority_queue <p> pq[3];
int f[N][3],vis[N],cn[N][3],s[3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin >> t;
    while(t--)
    {
        long long an = 0;
        cin >> n;
        while(!pq[0].empty())  pq[0].pop();
        while(!pq[1].empty())  pq[1].pop();
        while(!pq[2].empty())  pq[2].pop();
        s[0] = s[1] = s[2] = 0;
        for(int i = 1;i<=n;i++)
        {
            cin >> f[i][0] >> f[i][1] >> f[i][2];
            cn[i][0] = cn[i][1] = cn[i][2] = 0;
            if(f[i][0] >= f[i][1] && f[i][0] >= f[i][2])
                an += f[i][0],vis[i] = 0,cn[i][0] = 1,pq[0].push({i,1,f[i][1]-f[i][0]}),pq[0].push({i,2,f[i][2]-f[i][0]}),s[0]++;
            else if(f[i][1] >= f[i][0] && f[i][1] >= f[i][2])
                an += f[i][1],vis[i] = 1,cn[i][1] = 1,pq[1].push({i,2,f[i][2]-f[i][1]}),pq[1].push({i,0,f[i][0]-f[i][1]}),s[1]++;
            else if(f[i][2] >= f[i][1] && f[i][2] >= f[i][0])
                an += f[i][2],vis[i] = 2,cn[i][2] = 1,pq[2].push({i,1,f[i][1]-f[i][2]}),pq[2].push({i,0,f[i][0]-f[i][2]}),s[2]++;
        }
            // cout << s[0] <<" " << s[1] <<" " << s[2] <<"\n";
        while(s[0] > n/2 || s[1] > n/2 || s[2] > n/2)
        {
            // cout << s[0] <<" " << s[1] <<" " << s[2] <<"\n";
            while(s[0] > n/2)
            {
                long long w = pq[0].top().w;
                int u = pq[0].top().u;
                int t = pq[0].top().t;
                pq[0].pop();
                if(vis[u])
                    continue;
                an += w;
                s[0]--;
                cn[u][t] = 1;
                vis[u] = t;
                s[t]++;
                for(int i = 0;i<3;i++)
                    if(!cn[u][i])
                        pq[t].push({u,i,f[u][i]-f[u][t]});
            }
            // cout << s[0] <<" " << s[1] <<" " << s[2] <<"\n";
            while(s[1] > n/2)
            {
                long long w = pq[1].top().w;
                int u = pq[1].top().u;
                int t = pq[1].top().t;
                pq[1].pop();
                if(vis[u] != 1)
                    continue;
                an += w;
                s[1]--;
                cn[u][t] = 1;
                vis[u] = t;
                s[t]++;
                for(int i = 0;i<3;i++)
                    if(!cn[u][i])
                        pq[t].push({u,i,f[u][i]-f[u][t]});
            }
            // cout << s[0] <<" " << s[1] <<" " << s[2] <<"\n";
            while(s[2] > n/2)
            {
                long long w = pq[2].top().w;
                int u = pq[2].top().u;
                int t = pq[2].top().t;
                pq[2].pop();
                if(vis[u] != 2)
                    continue;
                an += w;
                s[2]--;
                cn[u][t] = 1;
                vis[u] = t;
                s[t]++;
                for(int i = 0;i<3;i++)
                    if(!cn[u][i])
                        pq[t].push({u,i,f[u][i]-f[u][t]});
            }
            // cout << s[0] <<" " << s[1] <<" " << s[2] <<"\n";
        }
        cout << an <<"\n";
    }
    return 0;
}