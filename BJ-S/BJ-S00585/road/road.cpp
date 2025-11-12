

#include <bits/stdc++.h>

using namespace std;

int G1[10009][10009];
int G2[10009][10009];
int M[19][10009];
int n,m,k;
queue<int> q;
queue<int> q1;
int vis[10009];

long long prim1 () {
    long long sum = 0;
    q.push(1);
    for (int i = 1; i < n; i++) {
        int I = q.front();
        q.pop();
        int mini = 1e9;
        int thej = 0;
        for (int j = 1; j <= n; j++) {
            if (G1[I][j] != 0) {
                vis[j] = min(vis[j],G1[I][j]);
            }
            if (vis[j]==0) {
                continue;
            }
            if (vis[j]<mini) {
                mini = vis[j];
                thej = j;
            }
        }

        q.push(thej);
        sum += vis[thej];
        vis[thej] = 0;
        G1[I][thej] = 0;
        G1[thej][i] = 0;
    }
    return sum;
}

long long prim2 () {
    long long sum = 0;
    q1.push(1);
    for (int i = 1; i < n+1; i++) {
        int I = q1.front();
        q1.pop();
        int mini = 1e9;
        int thej = 0;
        for (int j = 1; j <= n+1; j++) {
            if (G2[I][j] != 0) {
                vis[j] = min(vis[j],G2[I][j]);
            }
            if (vis[j]==0) {
                continue;
            }
            if (vis[j]<mini) {
                mini = vis[j];
                thej = j;
            }
        }

        q1.push(thej);
        sum += vis[thej];
        vis[thej] = 0;
        G2[I][thej] = 0;
        G2[thej][i] = 0;
    }
    return sum;
}

int main () {

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y,z;
        cin >> x >> y >> z;
        G1[x][y] = z;
        G1[y][x] = z;
        G2[x][y] = z;
        G2[y][x] = z;
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1e9;
    }
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= n; j++) {
            cin >> M[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        int z = 1e9;
        for (int j = 1; j <= k; j++) {
            z = min(z, M[j][i]);
        }
        G2[i][n+1] = z;
        G2[n+1][i] = z;
    }
    long long x = prim1();
    for (int i = 1; i <= n+1; i++) {
        vis[i] = 1e9;
    }
    long long y = prim2();
    cout << min(x,y) << endl;

    return 0;
}
