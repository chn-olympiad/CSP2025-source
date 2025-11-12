#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
int T,n,e,maxn,maxflow,sum[MAXN],last[MAXN],in[MAXN][MAXN];
bool open[MAXN][MAXN];
vector <pair <int,int>> t[MAXN];
int zdl()
{
    memset(last,-1,sizeof(last));
    queue <pair <int,int>> nxt;
    nxt.push({0,0x3f3f3f});
    while (not nxt.empty())
    {
        int u = nxt.front().first;
        int flow = nxt.front().second;
        //cout << u << "choose" << endl;
        if (u == e)
        {
            //cout << "I'm" << u << "makeflow:" << flow << endl;
            return flow;
        }
        nxt.pop();
        for (int i = 0;i < t[u].size();i++)
        {
            int v = t[u][i].first,w = t[u][i].second;
            //cout << v << "? " << "data:" << last[v] << ',' << w << ',' << open[u][v] << ';' << endl;
            //cout << "try:" << u << "to" << v << "and" << open[u][v] << endl;
            if ((last[v] == -1) and (w > 0) and (open[u][v]))
            {
                last[v] = u;
                //cout << "the last of" << v << "is" << u << endl;
                //cout << u << "to" << v << "the max is" << w << "so flow is"<< min(flow,w) << endl;
                nxt.push({v,min(flow,w)});
            }
        }
    }
    return -1;
}
int check()
{
    while (true)
    {
        //cout << 111 << endl;
        int flow = zdl();
        //cout << "hhh" << endl;
        if (flow == -1)
        {
            break;
        }
        maxflow += flow;
        int now = e;
        //cout << "let go" << endl;
        while (now != 0)
        {
            int backed = last[now];
            //cout << 222 << endl;
            //cout << backed << ' ' << now << ' ' << endl;
            t[backed][in[now][backed]].second -= flow;
            //cout << 222 << endl;
            t[now][in[backed][now]].second += flow;
            //cout << 222 << endl;
            now = backed;
            //cout << 222 << endl;
        }
    }
    return maxflow;
}
bool cmp(pair <int,int> a,pair <int,int> b)
{
    return a.first > b.first;
}
void makemax()
{
    for (int i = 1;i <= n;i++)
    {
        for (int j = n + 1;j <= n + 3;j++)
        {
            if (open[i][in[j][i]])
            {
                sum[i] = max(sum[i],t[i][in[j][i]].second);
            }
        }
        //cout << "max" << i << "is" << sum[i] << endl;
        maxn += sum[i];
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    for (int i = 1;i <= T;i++)
    {
        //cout << 111 << endl;
        cin >> n;
        //cout << 111 << endl;
        memset(sum,0,sizeof(sum));
        maxn = 0;
        e = n + 4,maxflow = 0;
        //0;1 - n;n + 1 -- n + 3;n + 4;
        for (int j = 1;j <= n;j++)
        {
            for (int k = n + 1;k <= n + 3;k++)
            {
                int a;
                cin >> a;
                //cout << 111 << endl;
                t[j].push_back({k,a});
                t[k].push_back({j,0});
                in[k][j] = t[j].size() - 1;
                in[j][k] = t[k].size() - 1;
            }
            //cout << 222 << endl;
        }
        memset(open,true,sizeof(open));
        for (int j = n + 1;j <= n + 3;j++)
        {
            vector <pair<int,int>> num;
            for (int k = 1;k <= n;k++)
            {
                num.push_back({t[k][in[j][k]].second,k});
                //cout << k << "to" << j << "(me) is" << t[k][in[j][k]].second << endl;
            }
            sort(num.begin(),num.end(),cmp);
            int p = num.size() - 1;
            while (p + 1 > (n / 2))
            {
                int v = num[p].second;
                //cout << "so" << v << "is not suitable to with " << j << "(me)" << endl;
                open[v][j] = false;
                p--;
            }
        }
        makemax();
        //cou
        for (int j = 1;j <= n;j++)
        {
            t[0].push_back({j,sum[j]});
            t[j].push_back({0,0});
            in[0][j] = t[j].size() - 1;
            in[j][0] = t[0].size() - 1;
        }
        //cout << 222 << endl;
        for (int j = n + 1;j <= n + 3;j++)
        {
            t[j].push_back({e,maxn});
            t[e].push_back({j,0});
            in[j][e] = t[e].size() - 1;
            in[e][j] = t[j].size() - 1;
        }
        cout << check() << endl;
        //cout << 333 << endl;
        for (int i = 0;i <= n + 4;i++)
        {
            t[i].clear();
        }
    }
    return 0;
}
