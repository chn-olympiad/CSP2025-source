#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;
int t,n;
int a[maxn],b[maxn],c[maxn];
void dfs(){
    int ans = 0;
    int u1 = a[1]+b[2];ans = max(ans,u1);
    int u2 = a[1]+c[2];ans = max(ans,u2);
    int u3 = b[1]+c[2];ans = max(ans,u3);
    int u4 = a[2]+b[1];ans = max(ans,u4);
    int u5 = a[2]+c[1];ans = max(ans,u5);
    int u6 = b[2]+c[1];ans = max(ans,u6);
    cout << ans << endl;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i] >> b[i] >> c[i];
        if(n == 2){
            dfs();
        }
    return 0;
}
}