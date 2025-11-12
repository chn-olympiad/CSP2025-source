#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_VERSTAPPEN = 5e5 + 1;
int n, k;
int a[MAX_VERSTAPPEN];
bool vis[MAX_VERSTAPPEN];
int ans;
struct node{
    int l, r;
};
vector<node> q;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = i;j <= n;j ++){
            int sum = a[i];  
            bool f = 1;        
            for(int p = 0;p < q.size();p++){
                if((i >= q[p].l && j <= q[p].r) || (i <= q[p].r && j >= q[p].r) || (j >= q[p].l&&i <= q[p].l)){
                    f = 0;
                }
            }
            if(f == 0) continue;
            if(i != j){
                for(int x = i + 1;x <= j;x++){
                    sum ^= a[x];
                }
                if(sum == k){
                    ans ++;
                    //cout << i <<" " << j << endl;
                    q.push_back({i, j});
                }
            }
            else{
                if(sum == k){
                    ans++;
                    //cout << i <<" " << j << endl;
                    q.push_back({i, j});
                }
            }
        }
    }
    cout << ans;
    return 0;
}