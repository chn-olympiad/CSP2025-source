#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int fa[10015];
int cost[15];
int village[15][10005];
void init(int n) {
    for(int i = 1;i<=n;i++) {
        fa[i] = -1;
    }
}
int getfa(int x) {
    if(fa[x] == -1) return x;
    return fa[x] = getfa(fa[x]);
}
void mergefa(int x,int y) {
    int fax = getfa(x),fay = getfa(y);
    fa[fax] = fay;
}
priority_queue<pair<int,pair<int,pair<int,int> > >,vector<pair<int,pair<int,pair<int,int> > > >,greater<pair<int,pair<int,pair<int,int> > > > > q;

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        q.push({z,{x,{y,0}}});
    }
    for(int i = 1;i<=k;i++) {
        cin>>cost[i];
        for(int j = 1;j<=n;j++) {
            cin>>village[i][j];
        }
    }
    init(n);
    long long ans = 0;
    while(!q.empty()) {
        auto cur = q.top();
        q.pop();
        int x = cur.second.first;
        int y = cur.second.second.first;
        if(getfa(x) != getfa(y)) {
            mergefa(x,y);
            ans += cur.first;
        }
    }
    cout << ans << endl;
    return 0;
}
