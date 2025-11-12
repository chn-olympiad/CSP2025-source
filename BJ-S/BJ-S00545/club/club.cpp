#include<bits/stdc++.h>
using namespace std;
struct node{
    int x, y, z;
}a[100010], dp[100010];
int n, t, u, v, w;
int dfs(int step, int sum){
    if(step > n){
        return sum;
    }
    if(u == n/2){
        if(v == n/2){
            if(w == n/2){
                return sum;
            }else{
                w++;
                int s = dfs(step+1, sum+a[step].z);
                w--;
                return s;
            }
        }else{
            if(w == n/2){
                v++;
                int s = dfs(step+1, sum+a[step].y);
                v--;
                return s;
            }else{
                v++;
                int s = dfs(step+1, sum+a[step].y);
                v--;
                w++;
                s = max(s, dfs(step+1, sum+a[step].z));
                w--;
                return s;
            }
        }
    }else{
        if(v == n/2){
            if(w > n/2){
                u++;
                int s = dfs(step+1, sum+a[step].x);
                u--;
                return s;
            }else{
                u++;
                int s = dfs(step+1, sum+a[step].x);
                u--;
                w++;
                s = max(s, dfs(step+1, sum+a[step].z));
                w--;
                return s;
            }
        }else{
            if(w == n/2){
                u++;
                int s = dfs(step+1, sum+a[step].x);
                u--;
                v++;
                s = max(s, dfs(step+1, sum+a[step].y));
                v--;
                return s;
            }else{
                u++;
                int s = dfs(step+1, sum+a[step].x);
                u--;
                v++;
                s = max(s, dfs(step+1, sum+a[step].y));
                v--;
                w++;
                s = max(s, dfs(step+1, sum+a[step].z));
                w--;
                return s;
            }
        }
    }
}
int cmp(node a, node b){
    return a.x > b.x;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        bool f1 = 0, f2 = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            if(a[i].y != 0){
                f1 = 1;
            }
            if(a[i].z != 0){
                f2 = 1;
            }
        }
        if(n <= 30){
            u = 0, v = 0, w = 0;
            cout << dfs(1, 0) << endl;
        }else if(f1 && f2){
            sort(a+1, a+n+1, cmp);
            int ans = 0;
            for(int i = 1; i <= n/2; i++){
                ans += a[i].x;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
