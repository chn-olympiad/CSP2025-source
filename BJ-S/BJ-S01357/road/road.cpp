#include <bits/stdc++.h>

using namespace std;

const int MAXN = 23167;

int s[MAXN];

int n,m,k;

struct edge
{
    int from,to,w;
};
edge G[MAXN];

struct country
{
    int my;
    int a[MAXN];
};
country c[MAXN];

int find(int x)
{
    return x==s[x]?x:x=find(s[x]);
}

bool cmp(edge e1,edge e2)
{
    return e1.w < e2.w;
}

bool isover(int totalcity,int totalroad)
{
    bool flag = true;//1 means every cities are connected
    for (int i=1;i<n;i++)
        if (find(i) != find(i+1))
            flag = false;
    return (totalcity-1 == totalroad) && flag;
}

int main()
{
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    int totalcity = n;
    int totalroad = 0;
    int ans = 0;
    for (int i=1;i<=n;i++)
        s[i] = i;
    for (int i=1;i<=m;i++)
        cin >> G[i].from >> G[i].to >> G[i].w;
    for (int i=1;i<=k;i++)
    {
        cin >> c[i].my;
        for (int j=1;j<=n;j++)
            cin >> c[i].a[j];
    }
    sort(G+1,G+m+1,cmp);
    int p = 1;
    while(!isover(totalcity,totalroad) && p<=m)
    {
        int f = G[p].from;
        int t = G[p].to;
        if (find(f) != find(t))
        {
            int mintotalprocountrycost = 1e9;
            for (int i=1;i<=k;i++)
            {
                int cost=0;
                cost += c[i].my;
                cost += c[i].a[f]+c[i].a[t];
                mintotalprocountrycost = min(mintotalprocountrycost,cost);
            }
            if (G[p].w < mintotalprocountrycost)
            {
                //cout << ans << " + G[ " << p << "].w merge( " << f << "," << t << ")" << totalroad << " ++" << endl;
                ans += G[p].w;
                s[find(f)] = s[find(t)];
                totalroad ++;
            }
            else
            {
                //cout << ans << " + " << mintotalprocountrycost << ' ' <<totalroad << "+2 " << ' ' << totalcity << "++" << endl;
                ans += mintotalprocountrycost;
                totalroad += 2;
                totalcity ++;
            }
        }
        p ++;
    }
    cout << ans;
    return 0;
}
