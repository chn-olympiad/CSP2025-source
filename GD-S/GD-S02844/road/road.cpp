#include <bits/stdc++.h>
using namespace std;
#define _ 1100005

int rd()
{
    int x = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return x * f;
}

struct node{int u, v, w;}e[_], ed[11][1005];
bool cmp(node a, node b) {return a.w < b.w;}

int fa[_];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

long long ans;
int n, m, k, cnt;
int fu, fv;


void work1()
{
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++) e[++m] = ed[i][j];
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= m && cnt != n + k - 1; i++)
    {
        fu = find(e[i].u), fv = find(e[i].v);
        if(fu == fv) continue;
        
        cnt ++; fa[fu] = fv; ans += e[i].w;
    }
    cout << ans;
}

int chs[11], c[11];

struct srt{int w, id, rk; bool operator < (const srt &o) const{return w > o.w;};}awa;

void dfs(int stp, long long sum, int v)
{
    if(stp > k)
    {
	// for(int i = 1; i < stp; i++) cout << chs[i];
	// cout << "###\n";
        cnt = 0;
        priority_queue <srt> q;
        q.push({e[1].w, 0, 1});
        for(int i = 1; i <= k; i++) if(chs[i]) q.push({ed[i][1].w, i, 1});
        for(int i = 0; i < n+k+5; i++) fa[i] = i;
        while(q.size() && cnt != v)
        {
            awa = q.top(), q.pop();
            if(awa.id == 0)
            {
                fu = find(e[awa.rk].u), fv = find(e[awa.rk].v);
                // cout << awa.w << " " << e[awa.rk].u << " " << e[awa.rk].v << "\n";
                if(fu != fv) {cnt ++; fa[fu] = fv; sum += e[awa.rk].w;}
                if(awa.rk != m) q.push({e[awa.rk+1].w, 0, awa.rk+1});
            }
            else
            {
                fu = find(ed[awa.id][awa.rk].u), fv = find(ed[awa.id][awa.rk].v);
                // cout << awa.w << " " << ed[awa.id][awa.rk].u << " " << ed[awa.id][awa.rk].v << "\n";
                if(fu != fv) {cnt ++; fa[fu] = fv; sum += ed[awa.id][awa.rk].w;}
                if(awa.rk != n) q.push({ed[awa.id][awa.rk+1].w, awa.id, awa.rk+1});
            }
        }
        // cout << sum ;
        // cout << "\n";
        if(cnt == v)
            ans = min(ans, sum);
        return;
    }
    chs[stp] = 0;
    dfs(stp+1, sum, v);
    chs[stp] = 1;
    dfs(stp+1, sum + c[stp], v+1);
}

void work2()
{
    ans = 1e18;
    dfs(1, 0, n-1);
    cout << ans;
}

bool f, g;

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    for(int i = 0; i < _; i++) fa[i] = i;
    n = rd(), m = rd(), k = rd();
    for(int i = 1; i <= m; i++) e[i] = {rd(), rd(), rd()};
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= k; i++)
    {
        c[i] = rd();
        f |= c[i]; g = 0;
        for(int j = 1; j <= n; j++) ed[i][j] = {n + i, j, rd()}, g |= !ed[i][j].w;
        sort(ed[i]+1, ed[i]+n+1, cmp);
        f |= !g;
    }
    if(!f) work1();
    else work2();
    return 0;
}