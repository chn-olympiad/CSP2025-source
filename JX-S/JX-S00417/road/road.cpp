#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
#define int long long
int n, m, k, head[N], vis1[N * 2], vis2[N * 2], a[15][N], fa[N], tong[N], ans = 0x3f3f3f3f, num, sum;
struct node{
    int u, v, w, id, ww, flag;
}edge[M * 2];
int edge2[N * 2], c[N];
void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
}
int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
bool cmp(node x, node y){
    return x.w < y.w;
}
int kus(int nn, int mm){
    int num2 = 0, ans1 = 0;
    sort(edge + 1, edge + 1 + mm, cmp);
    for(int i = 1; i <= mm; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int ii = edge[i].flag;
        int w = edge[i].w;
        if(edge[i].id == 1 && tong[ii] != 0 && ii != 0){
            w = edge[i].ww;
        }
        else if(edge[i].id == 1 && tong[ii] == 0 && ii != 0){
            w = edge[i].w;
            tong[ii]++;
        }
       // cout << w << endl;
        int fu = find(u);
        int fv = find(v);
        if(fu != fv){
            fa[fu] = fv;
            ans1 += w;
            nn--;
            if(nn == 1) break;
        }
    }
   // cout << endl;
    return ans1;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> n >> m >> k;
    init();
    for(int i = 1; i <= m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].id = edge[i].flag = 0;
        edge[i].ww = -1;
    }
    ans = kus(n, m);
    num = m;
    sum = n;
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        int nummm = 0;
        sum++;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) nummm++;
            edge[++num].u = sum;
            edge[num].v = j;
            edge[num].w = a[i][j] + c[i];
            edge[num].id = 1;
            edge[num].flag = sum;
            edge[num].ww = a[i][j];
        }
        for(int i = 1; i <= sum; i++) fa[i] = i;
        for(int i = n; i <= n + k + 1; i++) tong[i] = 0;
        if(c[i] != 0 || nummm != n){
            num -= n;
            sum -= 1;
            continue;
        }
        int numm = kus(sum, num);
        if(numm >= ans){
            num -= n;
            sum -= 1;
        }
        else ans = numm;
    }

    for(int i = 1; i <= k; i++){
        cin >> c[i];
        sum = n + 1;
        num = m;
        for(int j = 1; j <= n; j++){
            edge[++num].u = sum;
            edge[num].v = j;
            edge[num].w = a[i][j] + c[i];
            edge[num].id = 1;
            edge[num].flag = sum;
            edge[num].ww = a[i][j];
        }
        for(int i = 1; i <= sum; i++) fa[i] = i;
        for(int i = n; i <= n + k + 1; i++) tong[i] = 0;
        int numm = kus(sum, num);
        ans = min(ans, numm);
    }
    cout << ans;
    return 0;
}
