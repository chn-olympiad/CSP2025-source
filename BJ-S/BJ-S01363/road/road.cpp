#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 20, M = 15;

struct node{
    ll v, w;
};

vector<node> g[N], e[N];

ll p[N], a[M][N], ans = 1e18;

int n, m, k;

bool vis[N];

ll dis[N];

bitset<15> bs;

void dfs(int k, int cnt, ll sum){
	//cout << k << " " << cnt << " " << sum << endl;
    if(sum > ans) return ;
    if(cnt == 1){
		ans = sum; return ;
    }
    for(auto i : g[k]){
        if(!vis[i.v]){
            vis[i.v] = 1;
            dfs(i.v, cnt - 1, sum + i.w);
            vis[i.v] = 0;
        }
    }
    for(auto i : e[k]){
        if(!vis[i.v]){
            vis[i.v] = 1;
            if(i.v >= 1 && i.v <= n) dfs(i.v, cnt - 1, sum + i.w);
            else dfs(i.v, cnt, sum + i.w);
            vis[i.v] = 0;
        }
    }
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z}); g[y].push_back({x, z});
    }
    for(int i = 1; i <= k; i++){
        cin >> p[i];
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    ll sum = 0;
    for(int i = 0; i < (1 << k); i++){
        bs = i;
        for(int j = 1; j <= n + k; j++) vis[j] = 0;
        for(int j = 1; j <= n + k; j++) e[j].clear();
        sum = 0;
        for(int j = 0; j < k; j++){
            if(bs[j]){
                sum += p[j + 1];
                for(int k = 1; k <= n; k++){
                    e[n + j + 1].push_back({k, a[j + 1][k]});
                    e[k].push_back({n + j + 1, a[j + 1][k]});
                }
            }
        }
        //for(int i = 1; i <= n + k; i++){
		//	for(auto j : e[i])cout << i << " " << j.v << " " << j.w << " " << endl;
		//}
        vis[1] = 1;
        dfs(1, n, sum);
        //cout << sum << " " << ans << endl << endl;
    }
    cout << ans << endl;
}
