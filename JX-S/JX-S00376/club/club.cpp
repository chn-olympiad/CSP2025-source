#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5e5 + 10;
int t,sum[6],ans;
struct node{
    int x,id;
}a[20],f[N][5];
priority_queue<int> q[5];
bool cmp(node xx,node yy){
    return xx.x > yy.x;
}
void solve(){
    for (int i = 1; i <= 3; i++) while(!q[i].empty()) q[i].pop();
    int n,ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++) cin >> a[j].x,a[j].id = j;
        sort(a+1,a+3+1,cmp);
        for (int j = 1; j <= 2; j++) f[i][j] = a[j];
    }
    for (int i = 1; i <= n; i++){
        int aa = f[i][1].x,bb = f[i][1].id,cc = f[i][2].x,dd = f[i][2].id;
        q[bb].push(cc - aa);
        ans+=aa;
    }
    for (int i = 1; i <= 3; i++){
        while(q[i].size() > n/2){
            ans+=q[i].top();
            q[i].pop();
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}