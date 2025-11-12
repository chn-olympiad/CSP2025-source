#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
    int x, y, z;
}a[N];
int vis[N];
struct xyz{
    int num, idx;
}X[N], Y[N], Z[N];
bool cmp(int a, int b) {
    return a>b;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        memset(vis, 0, sizeof(vis));
        int x[N];
        int tot=0;
        for (int i=1; i<=n; i++) {
            int y, z;
            cin>>x[i]>>y>>z;
        }
        sort(x+1, x+n+1, cmp);
        for (int i=1; i<=n/2; i++) {
            tot+=x[i];
        }
        cout<<tot;
    }

    return 0;
}
