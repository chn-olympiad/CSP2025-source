#include<bits/stdc++.h>

using namespace std;
const int N = 4e6 + 10;
long long n, m, k;
struct edge{
    long long a, b, c;
}w[N];
long long idx = 0;
long long s[N];
bool cmp(edge a, edge b)
{
    return a.c < b.c;
}
long long fa[N];
long long find(long long x)
{
    if(x != fa[x]) return fa[x] = find(fa[x]);
    else return x;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(long long i = 1; i <= m; i ++ )
    {
        long long a, b, c;
        cin >> a >> b >> c;
        w[++ idx] = {a, b, c};
    }
    for(int i = 1; i <= k; i ++ )
    {
        long long c;
        cin >> c;
        long long root = 0;
        for(int j = 1; j <= n; j ++ )
        {
            cin >> s[j];
            if(s[j] == 0) root = j;
        }
        for(int j = 1; j <= n; j ++ )
        {
            if(j != root) w[ ++ idx] = {root, j, s[j]};
        }
    }
    sort(w + 1, w + idx + 1, cmp);
    for(long long i = 1; i <= n; i ++ ) fa[i] = i;
    long long k = 0;
    long long ans = 0;
    for(long long i = 1; i <= idx; i ++ )
    {
        long long a = find(w[i].a), b = find(w[i].b);
        if(a != b)
        {
            ans += w[i].c;
            k ++ ;
            fa[a] = b;
        }
        if(k == n - 1) break;
    }
    cout << ans << endl;
}
