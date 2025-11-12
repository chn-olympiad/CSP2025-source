#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e4 + 50 , M = 1e6 + 50 , K = 11;
struct node{
    int u , v , w , id;
}a[M] , d[N * K];
int n , m , k , f[N] , g[N] , c[N];
vector <int> e;
queue <int> q;
bool cmp(node x , node y){
    return x.w < y.w;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
bool merge(int x , int y){
    x = find(x) , y = find(y);
    if (g[x] > g[y]) swap(x , y);
    if (x == y) return 0;
    g[f[x] = y] += g[x];
    return 1;
}
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll ans = 1e18 , sum , l = 0;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a + 1 , a + m + 1 , cmp);
    for (int i = 1;i <= n;i++) f[i] = i , g[i] = 1;
    for (int i = 1;i <= m;i++){
        if (merge(a[i].u , a[i].v)){
            d[++l] = a[i];
            d[l].id = 0;
        }
    }

    for (int i = 1;i <= k;i++){
        cin >> c[i];
        for (int j = 1;j <= n;j++){
            cin >> d[++l].w;
            d[l].u = n + i , d[l].v = j , d[l].id = i;
        }
    }
    sort(d + 1 , d + l + 1 , cmp);
    for (int i = 0;i < (1 << k);i++){
        sum = 0;
        for (int j = 1;j <= k;j++){
            if (i & (1 << j - 1)) sum += c[j];
        }
        for (int j = 1;j <= n + k;j++) f[j] = j , g[j] = 1;
        for (int j = 1;j <= l;j++){
            if ((!d[j].id || (i & (1 << d[j].id - 1))) && merge(d[j].u , d[j].v)) sum += d[j].w;
        }
        ans = min(ans , sum);
    }
    cout << ans << '\n';
    return 0;
}