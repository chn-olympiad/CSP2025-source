#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 100,M = 1e6 + 10;
int n,m,k;
struct node{
    int x,y,w;
    bool operator < (const node &ret) const{\
        return w < ret.w;
    }
};
int fa[N];
vector<node> e,e2;
int ans = LONG_LONG_MAX;
int a[15][N];
int c[N];

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}


void cfa(){
    sort(e2.begin(),e2.end());
    for(int i = 1;i <= n + 10;i++) fa[i] = i;
}

void kru(bool f,int x){
    int sum = 0;
    for(auto i : e2){
        int fx = find(i.x),fy = find(i.y);
        if(fx == fy) continue;
        fa[fx] = fy;
        sum += i.w;
        if(f) e.push_back(i);
    }
    ans = min(ans,sum + x);
}


void lian(int num){
    int now = 0;
    e2.clear();
    for(auto i : e) e2.push_back(i);
    for(int i = 0;i < k;i++){
        if((num >> i) & 1){
            now += c[i + 1];
            for(int j = 1;j <= n;j++) e2.push_back({n + i + 1,j,a[i + 1][j]});
        }
    }
    cfa();
    kru(0,now);
}

void dfs(int x,int num){
    if(x == k + 1){
        lian(num);
        return ;
    }
    dfs(x + 1,num * 2);
    dfs(x + 1,num * 2 + 1);
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        e2.push_back({x,y,w});
    }
    for(int i = 1;i <= k;i++){
        cin>>c[i];
        for(int j = 1;j <= n;j++) cin>>a[i][j];
    }
    cfa();
    kru(1,0);
    dfs(1,0);
    cout<<ans<<endl;
}
