#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 2;
int n;
struct P{
    int a[3];
}a[N];

struct PQ{
    int id, id2, s;

    inline bool operator < (const PQ &x) const{
        return s < x.s;
    }
};
priority_queue <PQ> q[3];
int id[N];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T_, cnt[3];
    int ans, _ans[3], maxx;

    cin >> _T_;
    while(_T_ --){
        ans = 0;
        for(int i = 0; i < 3; i ++){
            while(!q[i].empty()) q[i].pop();
            cnt[i] = 0;
        }

        cin >> n;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < 3; j ++){
                cin >> a[i].a[j];
            }
        }

        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < 3; j ++){
                _ans[j] = ans;
            }
            for(int j = 0; j < 3; j ++){
                while(!q[j].empty() && id[q[j].top().id] != j) q[j].pop();

                if(cnt[j] < (n >> 1)){
                    _ans[j] += a[i].a[j];
                }
                else{
                    _ans[j] += a[i].a[j] + q[j].top().s;
                }
            }

            maxx = 0;
            for(int j = 0; j < 3; j ++){
                maxx = max(maxx, _ans[j]);
            }

            for(int j = 0; j < 3; j ++){
                if(maxx != _ans[j]) continue;
                ans = _ans[j];

                id[i] = j;
                if(cnt[j] < (n >> 1)){
                    cnt[j] ++;
                    for(int k = 0; k < 3; k ++){
                        if(k == j) continue;
                        q[j].push({i, k, a[i].a[k] - a[i].a[j]});
                    }
                }
                else{
                    cnt[q[j].top().id2] ++;
                    id[q[j].top().id] = q[j].top().id2;
                    q[j].pop();

                    for(int k = 0; k < 3; k ++){
                        if(k == j) continue;
                        q[j].push({i, k, a[i].a[k] - a[i].a[j]});
                    }
                }

                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

