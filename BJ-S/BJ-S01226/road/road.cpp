#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>
#define ll long long
using namespace std;

struct edge{
    int to,w;
};
int n,m,k,c[15],a[15][10005];
vector<edge> v[10005];
unordered_map<int,int> mp[10005];

int vis[10005],dis[10005];
ll prim(){
    ll ans = 0;
    for(int i = 2; i <= n; i++){
        dis[i] = INT_MAX;
    }
    vis[1] = 1;
    for(int i = 0; i < v[1].size(); i++){
        dis[v[1][i].to] = v[1][i].w;
    }
    for(int i = 2; i <= n; i++){
        int mn = INT_MAX,mni;
        for(int j = 1; j <= n; j++){
            //cout << j << " " << dis[j] << endl;
            if(vis[j]) continue;
            if(mn > dis[j]){
                mn = dis[j];
                mni = j;
            }
        }
        vis[mni] = 1;
        ans += mn;
        for(int j = 0; j < v[mni].size(); j++){
            dis[v[mni][j].to] = min(dis[v[mni][j].to],v[mni][j].w);
        }
        //cout << mn << endl;
    }
    return ans;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back({y,w});
        v[y].push_back({x,w});
        int X = v[x].size(),Y = v[y].size();
        mp[x][y] = X;
        mp[y][x] = Y;
    }
    for(int i = 1; i <= k; i++){
        scanf("%d",&c[i]);
        for(int j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(k == 0){
        cout << prim();
    }
    else{
        for(int i = 1; i <= k; i++){
            int t;
            for(int j = 1; j <= n; j++){
                if(a[i][j] == 0){
                    t = j;
                    break;
                }
            }
            for(int j = 1; j <= n; j++){
                if(j==t) continue;
                if(mp[t][j] == 0){
                    v[t].push_back({j,a[i][j]});
                    v[j].push_back({t,a[i][j]});
                }
                else{
                    v[t][mp[t][j]-1].w = min(v[t][mp[t][j]-1].w,a[i][j]);
                    v[j][mp[j][t]-1].w = min(v[j][mp[j][t]-1].w,a[i][j]);
                }
            }
        }
        /*
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j].to << " " << v[i][j].w << endl;
            }cout << endl;
        }
        */
        cout << prim();
    }
    return 0;
}

