#include <iostream>
using namespace std;

int n, m, k, ans;
int tr[10005][10005], v[10][10005], c[15];
int dis[10005];
bool inTree[10005];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        tr[x][y] = w;
        tr[y][x] = w;
    }

    for(int i=1; i<=k; i++){
        cin >> c[i];
        for(int j=1; j<=n; j++) cin >> v[i][j];
    }

    for(int x=1; x<=n-1; x++)
        for(int i=1; i<=k; i++)
            for(int y=x+1; y<=n; y++){
                if(x == y) continue;
                if(tr[x][y] == 0) tr[x][y] = v[i][x]+c[i]+v[i][y];
                tr[x][y] = min(tr[x][y], v[i][x]+c[i]+v[i][y]);
                tr[y][x] = tr[x][y];
            }
    inTree[1] = 1;

    for(int i=2; i<=n; i++) dis[i] = tr[1][i];

    for(int i=2; i<=n; i++){
        int mind=0x3f3f3f3f, s;

        for(int j=2; j<=n; j++){
            if(!inTree[j]){
                if(dis[j] < mind){
                    mind = dis[j];
                    s = j;
                }
            }
        }
        ans += dis[s];
        dis[s] = 0;
        inTree[s] = 1;
        for(int j=2; j<=n; j++){
            if(!inTree[j]){
                dis[j] = min(tr[j][s], dis[j]);
            }
        }
    }
    cout << ans;
    return 0;
}

