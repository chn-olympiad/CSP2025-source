#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define getchar getchar_unlocked
#define int long long
using namespace std;

struct Edge {
    int e;
    int d;

    bool operator> (const Edge& o) const { return d > o.d; }
};

vector<Edge> G[11005];
int n,m,k,u,v,w;
int num[15][10005];

bool tong[11005];
//int fa[20005];

/*
int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
*/

inline int read() {
    int s = 0;
    char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) { s = (s<<3)+(s<<1)+(ch^48); ch = getchar(); }
    return s;
}

inline int Solve1(const int &kkk) 
{
/*
    for(int i=1;i<=20000;i++)
        fa[i] = i;

    vector<pair<int,Edge>> egs;
    for(int i=1;i<=n;i++)
        for(auto j:G[i])
            egs.push_back(make_pair(i,j));
    sort(egs.begin(),egs.end(),[&](pair<int,Edge> a,pair<int,Edge> b){ return a.second.d < b.second.d; });

    int ans = 0;
    int tmp = 0, j = 0;
    while(tmp < n+kkk-1) {
        auto i = egs[j++];
        int a = i.first;
        int b = i.second.e;
        int d = i.second.d;
        int faa = find(a);
        int fab = find(b);
        if(faa == fab) continue;
        ans += d; fa[faa] = fab;
        tmp++;
    } return ans;
*/

    memset(tong,0,sizeof tong);
    memset(tong,0,sizeof tong);

    int ans = 0;
    int tmp = 1;
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;

    for(auto i:G[1])
        q.push(i);
    tong[1] = true;

    while(tmp < n+kkk) {
        auto t = q.top(); q.pop();
        if(tong[t.e]) continue;
        tong[t.e] = true;
        ans += t.d;
        for(auto i:G[t.e]) {
            if(tong[i.e]) continue;
            q.emplace(i);
        } tmp++;
    } return ans;
}

signed main() 
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n = read();
    m = read();
    k = read();
    for(register int i=0;i<m;i++) {
        u = read();
        v = read();
        w = read();
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    
    bool flagA = true;
    for(register int i=1;i<=k;i++) {
        bool flagB = false;
        for(register int j=0;j<=n;j++) {
            num[i][j] = read();
            if(num[i][0]) flagA = false;
            if(j && num[i][j] == 0) flagB = true;
        } flagA &= flagB;
    }
    if(flagA) {
        for(register int i=1;i<=k;i++)
            for(register int j=1;j<=n;j++)
                G[j].push_back({i+10000,num[i][j]});
        printf("%lld",Solve1(k)); return 0;
    } int ans = 9e18;
    cerr << clock() << endl;
    int st = clock();
    for(register int t=0;t<(1<<k);t++) {
        int tmp = 0;
        for(register int i=1;i<=k;i++)
            if(t & (1<<i-1)) {
                for(register int j=1;j<=n;j++) {
                    G[j].push_back({i+10000,num[i][j]});
                    G[i+10000].push_back({j,num[i][j]});
                } tmp += num[i][0];
            }
        tmp += Solve1(__builtin_popcount(t));
        ans = min(ans,tmp);
        for(register int i=1;i<=k;i++)
            if(t & (1<<i-1))
                for(register int j=1;j<=n;j++) {
                    G[j].pop_back();
                    G[i+10000].pop_back();
                }
    } printf("%lld",ans); cerr << clock()-st;
    return 0;
}