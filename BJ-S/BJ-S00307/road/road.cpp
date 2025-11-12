#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 500;
const int M  =2e6 + 50;
int m;
int n;
vector<pair<int,int>> g[N];
struct Edge
{
    int u,v,w;
}e[M];
int a[20][N];
int k;
int fa[N];
int c[100];
int ans;
int used[100];
bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}
int findfa(int x)
{
    if(fa[x] == x) return x;
    else fa[x] = findfa(fa[x]);
    return fa[x];
}
void addall()
{
    for(int i = 1;i <= k;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            g[n + i].push_back(make_pair(j,a[i][j]));
            g[j].push_back(make_pair(n + i,a[i][j]));
        }
    }
}
void add(int k)
{
    for(int i = 1;i <= n;i++)
    {
        g[n + k].push_back(make_pair(i,a[k][i]));
        g[i].push_back(make_pair(n + k,a[k][i]));
    }
}
int kruskal(int num)
{

    int tot = 0;
    int cnt = 0;
    int val = 0;
    for(int i = 1;i <= num;i++)
    {
		fa[i] = i;
        for(auto k : g[i])
        {

			if(i > n && used[i - n] == 0) continue;
			if(i <= n && k.first > n)
            {
                if(used[k.first - n] == 0) continue;
            }
            //cout << i << " " << k.first << " " << k.second << '\n';
            e[++tot].u = i;
            e[tot].v = k.first;
            e[tot].w = k.second;
        }
    }
    sort(e + 1,e + tot + 1,cmp);
    for(int i = 1;cnt < num - 1 && i <= tot;i++)
    {
        if(findfa(e[i].u) != findfa(e[i].v))
        {
            int fax = findfa(e[i].u);
            int fay = findfa(e[i].v);
            fa[fax] = fay;
            cnt++;
            val += e[i].w;
            //cout << e[i].u << " " << e[i].v << " "  << e[i].w << '\n';
        }
    }
    return val;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

    cin >> n >> m >> k;
    for(int i = 1;i <= n + k;i++) fa[i] = i;
    int flag = 0;
    for(int i = 1;i <= m;i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        if(c[i] != 0) flag = 1;
        bool haszero = 0;
        for(int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0) haszero = 1;
        }
        if(haszero == 0) flag = 1;
    }
    sort(e + 1,e + m + 1,cmp);
    int cnt = 0;
    for(int i = 1;cnt < n - 1 && i <= m;i++)
    {
        if(findfa(e[i].u) != findfa(e[i].v))
        {
            int fax = findfa(e[i].u);
            int fay = findfa(e[i].v);
            fa[fax] = fay;
            g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
            cnt++;
            ans += e[i].w;
        }
    }
    if(flag == 0)
    {
        addall();
        for(int i = 1;i <= k;i++) used[i] = 1;
        ans = min(ans,kruskal(n + k));
        cout << ans << '\n';
        return 0;
    }
    for(int i = 1;i <= k;i++)
    {
        used[i] = 1;
        add(i);
        int val = kruskal(n + i);

        for(int j = 1;j <= i;j++)
        {
			if(used[j]) val += c[j];
		}
		if(val < ans)
		{
			ans = val;
		}
		else
		{
			used[i] = 0;
		}
    }
   // for(int i = 1;i <= k;i++) cout << used[i] << '\n';
    cout << ans << '\n';
    return 0;
}
