#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Node{
    ll w;
    bool operator >(const Node& a) const{
        return w < a.w;
    }
};
priority_queue<Node, vector<Node>, greater<Node>> q;

long long d[15][1010], mp[1000][1000];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    if (n > 1000) return 0;
    for (int i = 1;i <= n;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[min(u, v)][max(u, v)] = w;
        if (q.size() < (n - 1)) q.push({w});
        else if (w < q.top().w){
            q.pop();
            q.push({w});
        }
    }
    for (int i = 1;i <= k;i++){
        int tot;
        cin >> tot;
        for (int j = 1;j <= n;j++){
            cin >> d[i][j];
        }
        for (int j = 1;j <= n;j++){
            for (int l = j + 1;l <= n;l++){
                ll temp = tot + d[i][j] + d[i][l];
                //cout << "mp:"<<mp[j][l] << " temp:" << temp << "   ";
                if (temp < mp[j][l] || mp[j][l] == 0){
                    if (q.size() < (n - 1)) q.push({temp});
                    else if (temp < q.top().w){
                        q.pop();
                        q.push({temp});
                    }
                }
            }
            //cout << endl;
        }
    }
    ll ans = 0;
    while(!q.empty()){
        ans += q.top().w;
        //cout << q.top().w << " ";
        q.pop();
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}