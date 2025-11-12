#include <bits/stdc++.h>
#define int long long
#define COUNTRY 0
#define ROAD 1
using namespace std;

int n, m, k, ret=0;
struct road {
    int u, v, w, type, from; };
bool operator<(road a, road b)  {
    return a.w>b.w; }
priority_queue<road> rd;
vector<int> country[11];
bool if_rebuilt[11];
int a[11];
int f[10001];

int find(int x)
{
    if (f[x]!=x)  f[x]=find(f[x]);
    return f[x];
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    // construct map(road is ready.)
    scanf("%lld%lld%lld", &n, &m, &k);

    for (int i=1; i<=n; i++)  f[i]=i;

    for (int i=0; i<m; i++)  {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        if (u>v)  swap(u, v);
        rd.push({u,v,w,ROAD,0});  }
    for (int i=1; i<=k; i++)  {
        scanf("%lld", &a[i]);
        for (int j=1; j<=n; j++)  {
            int x;
            scanf("%lld", &x);
            country[i].push_back(x);  }
        for (int j=1; j<n; j++)
            for (int k=j+1; k<=n; k++)
                rd.push({j, k, country[i][j-1]+country[i][k-1]+a[i], COUNTRY, i});
    }

    /*priority_queue<road> rd1=rd;
    while (rd1.size())  {
        printf("# %lld->%lld:%lld\n", rd1.top().u, rd1.top().v, rd1.top().w);
        rd1.pop();  } */

    while (rd.size())  {
        int u=rd.top().u, v=rd.top().v, w=rd.top().w, type=rd.top().type, from=rd.top().from;
        rd.pop();
        if (find(u)!=find(v))  {
            if (type==COUNTRY && if_rebuilt[from]==1)  w-=a[from];
            if (type==COUNTRY && if_rebuilt[from]==0)  if_rebuilt[from]=1;
            f[u]=f[v];
            ret+=w;  }
    }
    printf("%lld\n", ret);
    return 0;
}
