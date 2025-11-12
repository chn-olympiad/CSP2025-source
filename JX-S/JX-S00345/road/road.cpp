#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 500;
int n, m, k, ans, cut;
int f[N];

struct EDGE{int u, v, w;}edge[N];
struct ED{int to, w;};
vector<ED > E[N];

bool pd(EDGE a, EDGE b){
    return a.w < b.w;
}
int F(int x){
    if(f[x] != x)   return f[x] = F(f[x]);
    return x;
}

int dfs(int now, int e1, int e2, int &h, int fa, bool &boo){
    if(now == e1 || now == e2){
        if(boo == false)    return -1;
        else boo = false;
    }
    int zz;
    for(auto u : E[now]){
        if(u.to != fa){
            int num;
            if(!boo) h += u.w;
            dfs(u.to, e1, e2, h, now, boo);
            if(num == -1)   return -1;
        }
        else zz = u.w;
    }
    h+=zz;

    return 0;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>> n>> m>> k;
    for(int i=1; i<=n; i++) f[i] = i;
    for(int i=1; i<=m; i++)
        cin>> edge[i].u>> edge[i].v>> edge[i].w;
    sort(edge+1, edge+1+m, pd);

    for(int i=1; i<=m; i++){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        int p1 = F(u), p2 = F(v);
        if(p1 == p2)  continue;
        ans += w;
        f[p1] = p2;

        ED a1, a2;
        a1.to = u, a2.to = v;
        a1.w = a2.w = w;
        E[u].push_back(a1);
        E[v].push_back(a2);
    }
    if(k == 0){cout<<ans;   return 0;}
    int a, b;cin>>a >> b;

    for(int i=1; i<=k; i++){
        int w;cin>> w;
        int a[N], ANS = 21e8;
        for(int j=1; j<n;j++){
            cin>>a[i];
        }
        for(int l=1; l<=n; l++){
            for(int r=l+1; r<=n; r++){
                int a1 = a[l], a2 = a[r];
                int h=0;bool boo = true;
                dfs(1, l, r, h, -1, boo);
                ANS = min(ANS, w+a1+a1-h);
            }
        }
        if(ANS < 0) ans-=ANS;
    }
    cout<<ans;

    return 0;
}
