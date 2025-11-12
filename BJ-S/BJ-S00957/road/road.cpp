#include <bits/stdc++.h>

using namespace std;

int cntt;

struct edge{
    int from,to,val;
    edge(){};
    edge(int a,int b,int c){
        from = a;
        to = b;
        val = c;
    }
    bool operator < (const edge& road) const {
        return val > road.val;
    }
};
priority_queue<edge> q;
vector<edge> p1[100010];
edge q1[100010];

int fa[100010];

int c[100010];

int fr(int x){
    if(fa[x] == x) return x;
    return fa[x] = fr(fa[x]);
}
int n1,m1;
void Union(int x,int y){
    int fx = fr(x);
    int fy = fr(y);
    if(fx == fy) return ;
    fa[fy] = fx;
}

int kru(){
    long long ans = 0;
    int head = 1;
    int cnt = 0;
    for(int i = 1; i <= n1; i++){
        fa[i] = i;
    }
    while(cnt <= n1-1 && head <= m1){
        edge now = q.top();
//        cout << now.from << ' ' << now.to << ' ' << now.val << endl;
        q.pop();
        int fx = fr(now.from),fy = fr(now.to);
        if(fx == fy){
            head++;
            continue;
        }
        Union(now.from,now.to);
        ans += now.val;
        head++;
        cnt++;
    }
    return ans;
}

long long ans = 1e9;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        q.push({u,v,w});
        m1++;
    }
    n1 = n+k;
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        int w;
        for(int j = 1; j <= n; j++){
            cin >> w;
            q.push({i,j,w});
            m1++;
        }
    }
    int ans = kru();
    cout << ans;
    return 0;
}
