#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e4 + 10, maxm = 1e6 + 1e5;
int n, m, k;
int a[20][maxn];
int val[20];
int text1[20];

struct node{
    int v, u, w;
};
node edge[maxm];
node edge1[maxm];
int id = 0;

int dad[maxn + 10];


int find(int x){
    if(dad[x] == x) return x;
    return dad[x] = find(dad[x]);
}

void add(int x, int y){
    int xx = find(x);
    int yy = find(y);
    dad[xx] = yy;
}

bool cmp(node x, node y){
    return x.w < y.w;
}

ll kr(int x){
    ll ans = 0;
    sort(edge1 + 1, edge1 + 1 + id, cmp);
    int len = x;

    for(int i = 1; i <= id, len > 1; i ++){
        int from = edge1[i].u;
        int to = edge1[i].v;
        int ww = edge1[i].w;

        if(find(from) == find(to)) continue;
        //cout << i <<  " ";
        ans += ww;
        len --;
        add(from, to);
    }
    return ans;
}

int need[20];
ll maxx = 1e9 + 10;
void dfs(int now){
    //cout << now;
    if(now == k + 1){
        ll ans = 0;
        int x = n;
        int idd = id;
        for(int i = 1; i <= id; i ++) edge1[i] = edge[i];
        for(int i = 1; i <= n + 10; i ++) dad[i] = i;
        for(int i = 1; i <= k; i ++){
            //cout << need[i] << " ";
            if(need[i]){
                x ++;
                ans += val[i];
                for(int j = 1; j <= n; j ++){
                    edge1[++ id] = {n + i, j, a[i][j]};
                }
            }
        }
        //cout << id << " " << x << endl;
        maxx = min(maxx, ans + kr(x));
        id = idd;
        return ;
    }

    need[now] = 1;
    dfs(now + 1);
    need[now] = 0;
    dfs(now + 1);
}

void solve(){
    cin >> n >> m >> k;
    bool flag = 1;
    //cout << k;
    for(int i = 1; i <= n + 10; i ++) dad[i] = i;

    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        //id ++;
        edge[++ id] = {u, v, w};
    }
    //cout << id << " " << m << endl;
    for(int i = 1; i <= k; i ++){
        cin >> val[i];
        if(val[i] != 0) flag = 0;
        bool flag1 = 1;
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                flag1 = 0;
                text1[i] = j;
            }
        }
        if(flag1) flag = 0;
    }

    if(flag){
        for(int i = 1; i <= k; i ++){
            //cout << text1[i] << " ";
            for(int j = 1; j <= n; j ++){
                if(j == text1[i]) continue;
                edge[++ id] = {text1[i], j, a[i][j]};
            }
        }
    }

    if(flag || k == 0){
        //cout << 1;
        for(int i = 1; i <= id; i ++) edge1[i] = edge[i];
        cout << kr(n) << endl;
        return ;
    }
    //cout << 1;
    dfs(1);
    cout << maxx << endl;
    return ;
}

int main(){

    ios::sync_with_stdio();
    cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    solve();

    return 0;
}
/*
5 8 0
1 2 1
1 3 2
2 3 3
2 5 100
2 4 1
3 5 7
3 6 3
4 6 100
*/
