#include<bits/stdc++.h>
#define pii pair<int, int> 
#define fi first
#define se second

using namespace std;

const int N = 1e5 + 10;

struct node{
    int x, y, id;
}a[N];

pii t[5];

bool cmp(node a, node b){
    if(a.x != b.x) return a.x > b.x;
    return a.y > b.y;
}

int p[5];

priority_queue<int, vector<int>, greater<int> > q[5];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> t[1].fi >> t[2].fi >> t[3].fi; t[1].se = 1; t[2].se = 2; t[3].se = 3;
            sort(t + 1, t + 4);
            a[i] = {t[3].fi, t[2].fi, t[3].se};
        }
        for(int i = 1; i <= 3; i++){
			p[i] = 0;
            while(!q[i].empty()){
                q[i].pop();
            }
        }
        sort(a + 1, a + n + 1, cmp);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int tmp = p[a[i].id];
            if(tmp + 1 <= n / 2){
                q[a[i].id].push(a[i].x - a[i].y); ans += a[i].x; p[a[i].id]++;
            }else if(tmp == n / 2){
                int now = q[a[i].id].top();
                if(ans - now + a[i].x > ans + a[i].y){
                    q[a[i].id].pop(); q[a[i].id].push(a[i].x - a[i].y); ans = ans - now + a[i].x;
                }else ans += a[i].y;
            }
        }
        cout << ans << endl;
    }
}
