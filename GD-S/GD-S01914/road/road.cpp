#include<bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e4 + 1;
const lint inf = 0x3f3f3f3f3f3f3f3f;
vector<pair<lint,lint>> rural[N];
lint urban[11],urbanVal[11][N];
lint dis[N];
bool vis[N];
int n,m,k;
struct Node
{
    lint fro,to,val;
    bool operator < (const Node &o) const
    {
        if(val != o.val)
        {
            return val < o.val;
        }
        if(fro != o.fro)
        {
            return fro < o.fro;
        }
        return to < o.to;
    }
};
lint func()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    priority_queue<Node> pq;
    Node tmp;
    for(auto i : rural[1])
    {
        tmp.fro = 1;
        tmp.to = i.first;
        tmp.val = i.second;
        pq.push(tmp);
    }
    for(int i = 1;i <= n;i++)
    {
        tmp.fro = 1;
        tmp.to = i;
        tmp.val = urbanVal[1][i];
        pq.push(tmp);
    }
    lint fro,to,val,sum = 0;
    while(!pq.empty())
    {
        Node top = pq.top();
        pq.pop();
        fro = top.fro;
        to = top.to;
        val = top.val;
        vis[to] = 1;
        if(dis[to] > dis[fro] + val)
        {
            if(dis[to] != inf)
            {
                sum -= dis[to];
            }
            dis[to] = dis[fro] + val;
            sum += dis[fro] + val;
        }
        for(auto i : rural[to])
        {
            if(!vis[i.first])
            {
                tmp.fro = to;
                tmp.to = i.first;
                tmp.val = i.second;
                pq.push(tmp);
            }
        }
        if(to <= k)
        {
            for(int i = 1;i <= n;i++)
            {
                if(!vis[i])
                {
                    tmp.fro = to;
                    tmp.to = i;
                    tmp.val = urbanVal[to][i];
                    pq.push(tmp);
                }
            }
        }
    }
    return sum;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    lint fro,to,val;
    for(int i = 1;i <= m;i++)
    {
        cin >> fro >> to >> val;
        rural[fro].push_back({to,val});
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> urban[i];
        for(int j = 1;j <= n;j++)
        {
            cin >> urbanVal[i][j];
        }
    }
    cout << func();
    return 0;
}
