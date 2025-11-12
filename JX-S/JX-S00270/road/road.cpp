#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3 + 20;
const int MAXM = 1e6 + 6;
int c[MAXN];
int n, m, k;
struct Node{
    int from, to, w;
    friend bool operator <(Node x, Node y) {
        return x.w > y.w;
    }
}e[MAXM], e1[MAXM];
int fa[MAXN];
int rk[MAXN];
void init() {
    for(int i = 0; i < MAXN; i++) {
        fa[i] = i;
        rk[i] = 1;
    }
}
int find(int x) {
    if(fa[x] == x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int nx = find(x);
    int ny = find(y);
    if(nx > ny) {
        swap(nx, ny);
    }
    fa[ny] = nx;
}
int mmin = 1e16;
void K(int zt) {
    int cnt = 0;
    init();
    priority_queue<Node> q;
    for(int i = 1; i <= m; i++) {
        q.push(e[i]);
    }int result = 0;
    //cout << "------------------------" << endl;
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        if(zt >> (i - 1) & 1) {
            sum--;
            result += c[i];
            for(int j = 1; j <= n; j++) {
                q.push(e1[(i - 1) * n + j]);
                //cout << e1[(i - 1) * n + j].from << ' ' << e1[(i - 1) * n + j].to << endl;
            }
        }
    }
    //cout << sum << endl;
    if(result > mmin) {
        return ;
    }//cout << "ok" << endl;
    sum++;
    while(!q.empty()) {
        Node now = q.top();
        q.pop();
        cnt++;
        if(find(now.from) == find(now.to)) {
            continue;
        }
        merge(now.from, now.to);
        sum++;
        result += now.w;
        //cout << "x";
        if(sum == n) {
            //cout << "mmin:" << mmin << " " << result << endl;
            mmin = min(mmin, result);//cout << cnt << endl;
            return ;
        }
    }
}
bool sf = 0;
int xx[11][MAXN];
int thez[MAXN];
void K1() {
    init();
    priority_queue<Node> q;
    for(int i = 1; i <= m; i++) {
        q.push(e[i]);
    }int result = 0;
    //cout << "------------------------" << endl;
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            q.push({thez[i], j, xx[i][j]});
        }
    }
    //cout << sum << endl;
    if(result > mmin) {
        return ;
    }//cout << "ok" << endl;
    sum++;
    while(!q.empty()) {
        Node now = q.top();
        q.pop();
        if(find(now.from) == find(now.to)) {
            continue;
        }
        merge(now.from, now.to);
        sum++;
        result += now.w;
        //cout << "x";
        if(sum == n) {
            //cout << "mmin:" << mmin << " " << result << endl;
            mmin = min(mmin, result);//cout << cnt << endl;
            return ;
        }
    }
}

main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //cout << log10(pow(2, 5) * 1000000 * log2(1000));
    cin >> n >> m >> k;
    //cout << n<< ' ' << m << ' ' << k << endl;
    for(int i = 1; i <= m; i++) {
        cin >> e[i].from >> e[i].to >> e[i].w;
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        if(c[i] != 0) {
            sf = 1;
        }
        for(int j = 1; j <= n; j++) {
            int xb = (i - 1) * n + j;
            e1[xb].from = n + i;
            e1[xb].to = j;
            cin >> e1[xb].w;
            xx[i][j] = e1[xb].w;
            if(e1[xb].w == 0) {
                thez[i] = j;
            }
        }

    }
    for(int i = 0; i < (1 << k); i++) {
        K(i);//cout << i << endl;
    }
    cout << mmin << endl;
    return 0;
}
