#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t;
int n;
long long h[N];
struct K {
    int a, b, c;
}k[N];
long long maxn = 0;
void dfs(int x, int na, int nb, int nc, long long sum) {
    if(x == n + 1) {
         maxn = max(sum, maxn);
        return ;
    }if(na < n/2) dfs(x+1,na+1,nb,nc,sum+k[x].a);
    if(nb < n/2) dfs(x+1,na,nb+1,nc,sum+k[x].b);
    if(nc < n/2) dfs(x+1,na,nb,nc+1,sum+k[x].c);
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        maxn = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> k[i].a >> k[i].b >> k[i].c;
        }dfs(1,0,0,0,0);
        cout << maxn << "\n";
    }
    return 0;
}
