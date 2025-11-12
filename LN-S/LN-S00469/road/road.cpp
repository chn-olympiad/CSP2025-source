#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int N = 1e4+10,M = 1e6+10;
struct node{
    int x,y,z;
    bool operator <(const node &b)const{
        return z < b.z;
    }
}e[N];
int tot;
int n,m,k;
int c[N];
int fa[N * 2];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x,int y){
    x = find(x),y = find(y);
    if(x != y) fa[x] = y;
}
int cnt,sum;
void solve(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n + k * 2;i++) fa[i] = i;
    for(int i = 1;i <= m;i++){
        cin >> e[i].x >> e[i].y >> e[i].z;
    }
    tot = m;
    for(int i = n + 1;i <= n + k;i++){
        cin >> c[i];
        e[++tot] = {i + k,i,c[i]};
        for(int j = 1,x;j <= n;j++){
            cin >> x;
            e[++tot] = {i,j,x};
        }
    }
    sort(e + 1,e + tot + 1);
    for(int i = 1;i <= tot;i++){
        int x = e[i].x,y = e[i].y,z = e[i].z;
        if(find(x) == find(y)) continue;
        sum += z;
        merge(x,y);
        cnt++;
        if(cnt == n + k * 2 - 1) break;
    }
    cout << sum<<'\n';
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}
