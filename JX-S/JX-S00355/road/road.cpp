#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4 + 15;
const int M = 1e6 + 15;
//kao lv bao li mei jv na xie cun zhuang hui xuan
//fa xian chu shi bu zai zui xiao sheng cheng shu li de ken ding hou mian ye bu zai?????
//mlogm+2^k*(k*n+n*bingchaji)
//666 ji xian shu jv pao 1.05s     xiang xin CCF shao ye ji
//666 jia ge qi fa shi he bing jiu shi 0.9s le
struct ed{
    int u, v, w, op;
}edge[M + 10 * N];
int val[15];
bool cmp(ed p, ed q){
    return p.w < q.w;
}
int tot;
int n, m, k;
vector<ed> ve;//cun chu you yong de n + k * n tiao bian
long long ans;
struct BSE{
    int fa[N * 2], h[N * 2];
    void init(){
        for(int i = 1;i <= n + k;i++){
            fa[i] = i;
            h[i] = 1;
        }
    }
    int find(int x){
        if(fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
    void uni(int x, int y){
        int gx = find(x), gy = find(y);
        if(gx != gy){
            if(h[gx] > h[gy]) swap(gx, gy);
            fa[gx] = gy;
            h[gy] += h[gx];
        }
    }
}bse;
long long solve1(){
    bse.init();
    long long sum = 0;
    for(int i = 1;i <= m + n * k;i++){
        int u = edge[i].u, v = edge[i].v;
        if(edge[i].op){
            ve.push_back(edge[i]);
            continue;
        }
        if(bse.find(u) != bse.find(v)){
            bse.uni(u, v);
            ve.push_back(edge[i]);
            sum += edge[i].w;
        }
    }
    return sum;
}
long long solve2(int p){
    bse.init();
    long long sum = 0;
    for(int i = 1;i <= k;i++){
        if((p >> (i - 1)) & 1) sum += val[i];
    }
    for(int i = 0;i < ve.size();i++){
        int op = ve[i].op;
        if(op && !((p >> (op - 1)) & 1)) continue;
        int u = ve[i].u, v = ve[i].v;
        if(bse.find(u) != bse.find(v)){
 //           cout << p << ' ' << u << ' ' << v << ' ' << ve[i].w << '\n';
            bse.uni(u, v);
            sum += ve[i].w;
        }
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    double s1 = clock();
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v, w, 0};
    }
    tot = m;
    for(int i = 1;i <= k;i++){
        cin >> val[i];
        for(int j = 1;j <= n;j++){
            int x;
            cin >> x;
            edge[++tot] = {n + i, j, x, i};
        }
    }
    sort(edge + 1, edge + m + n * k, cmp);
    ans = solve1();
//    cout << ans << '\n';
    for(int i = 1;i < (1 << k);i++){
        ans = min(solve2(i), ans);
    }
    cout << ans;
    double s2 = clock();
    cerr << (s2 - s1) / CLOCKS_PER_SEC << '\n';
    return 0;
}
// i'm SBSBSBSBSB
// a~a~a~a~hahahahahawoshishabi
//wozenmezhemecai
