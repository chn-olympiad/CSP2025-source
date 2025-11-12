#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
struct node{
    int f1, v1;
    int f2, v2;
    int f3, v3;
    int cha;
}a[100005];
struct Node{
    int id, val, w;
    bool operator < (const Node &x) const{
        if(val == x.val){
            if(a[id].v1 != a[x.id].v1)
                return a[id].v1 > a[x.id].v1;
            if(a[id].v2 != a[x.id].v2)
                return a[id].v2 > a[x.id].v2;
            if(a[id].v1 != a[x.id].v1)
                return a[id].v3 > a[x.id].v3;
        }
        return val > x.val;
    }
};
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        memset(a, 0, sizeof(a));
        priority_queue <Node> q[4];
        cin >> n;
        int n_two = n/2;
        for(int i = 0;i < n;i++){
            int x, y, z;    cin >> x >> y >> z;
            if(x >= y && y >= z && x >= z)  a[i] = {1, x, 2, y, 3, z, x-y};
            if(x >= z && z >= y && x >= y)  a[i] = {1, x, 3, z, 2, y, x-z};
            if(y >= x && x >= z && y >= z)  a[i] = {2, y, 1, x, 3, z, y-x};
            if(y >= z && z >= x && y >= x)  a[i] = {2, y, 3, z, 2, y, y-z};
            if(z >= x && x >= y && z >= y)  a[i] = {3, z, 1, x, 2, y, z-x};
            if(z >= y && y >= x && z >= x)  a[i] = {3, z, 2, y, 1, x, z-y};
        }
        for(int i = 0;i < n;i++)
            q[a[i].f1].push({i, a[i].cha, a[i].v1});
        for(int i = 1;i <= 3;i++){
            while(q[i].size() > n_two){
                int now = q[i].top().id;
                q[a[now].f2].push({now, a[now].v2-a[now].v3, a[now].v2});
                q[i].pop();
            }
        }
        ll ans = 0;
        for(int i = 1;i <= 3;i++){
            while(!q[i].empty()){
                ans += q[i].top().w;
                q[i].pop();
            }
        }
        cout << ans <<'\n';
    }
    return 0;
}
