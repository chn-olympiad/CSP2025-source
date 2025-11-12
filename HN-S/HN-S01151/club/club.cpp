#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int n, ans, a[N][4], cnt[5], vis[N];

struct Node{
    int x, id;
};

bool cmp(Node a, Node b){
    return a.x > b.x;
}

bool cmp2(pair<pair<Node, Node>, Node> a, pair<pair<Node, Node>, Node> b){
    if(a.first.first.x != b.first.first.x){
        return a.first.first.x > b.first.first.x;
    }else if(a.first.second.x != b.first.second.x){
        return a.first.second.x > b.first.second.x;
    }else{
        return a.second.x > b.second.x;
    }
}

bool cmp3(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

bool cmp4(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

vector<Node> v;

pair<pair<Node, Node>, Node> f[N];

void dfs(int id, int x, int y, int z, int cnt){
    if(id == n + 1){
        ans = max(ans, cnt);
        return ;
    }
    if(x < n / 2){
        dfs(id + 1, x + 1, y, z, cnt + a[id][1]);
    }
    if(y < n / 2){
        dfs(id + 1, x, y + 1, z, cnt + a[id][2]);
    }
    if(z < n / 2){
        dfs(id + 1, x, y, z + 1, cnt + a[id][3]);
    }
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        if(n < 30){
            for(int i = 1, x, y, z; i <= n; i++){
                cin >> a[i][1] >> a[i][2] >> a[i][3];
            }
            dfs(1, 0, 0, 0, 0);
            cout << ans << '\n';
            ans = 0;
        }else{
            for(int i = 1, x, y, z; i <= n; i++){
                v.clear();
                cin >> x >> y >> z;
                v.push_back({x, 1});
                v.push_back({y, 2});
                v.push_back({z, 3});
                sort(v.begin(), v.end(), cmp);
                f[i] = {{v[0], v[1]}, v[2]};
            }
            fill(cnt + 1, cnt + 3 + 1, 0);
            sort(f + 1, f + n + 1, cmp2);
            /*
            for(int i = 1; i <= n; i++){
                cout << a[i].first.first.x << ' ' << a[i].first.second.x << ' ' << a[i].second.x << '\n';
            }*/
            fill(vis + 1, vis + n + 1, 0);
            for(int i = 1; i <= n; i++){
                if(cnt[f[i].first.first.id] < n / 2){
                    if(cnt[f[i].first.second.id] < n / 2){
                        if(f[i].first.first.x == f[i].first.second.x){
                            if(cnt[f[i].first.first.id] >= cnt[f[i].first.second.id]){
                                cnt[f[i].first.second.id]++;
                                ans += f[i].first.second.x;
                                vis[i] = 2;
                            }else{
                                cnt[f[i].first.first.id]++;
                                ans += f[i].first.first.x;
                                vis[i] = 1;
                            }
                            continue;
                        }
                    }
                    cnt[f[i].first.first.id]++;
                    ans += f[i].first.first.x;
                    vis[i] = 1;

                }else if(cnt[f[i].first.second.id] < n / 2){
                    cnt[f[i].first.second.id]++;
                    ans += f[i].first.second.x;
                    vis[i] = 2;

                }
            }
            cout << ans << '\n';
            ans = 0;
        }
    }
    return 0;
}
