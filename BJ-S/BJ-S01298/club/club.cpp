#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6+10;
int n,a[MAX][5],vis[MAX] = {},L[5] = {},summm[5] = {};
struct ssad{
    int sx,x,y;
}d[MAX];
bool cmp(ssad x,ssad y) {
    if(x.sx > y.sx) return 1;
    else if(x.sx == y.sx) {
        if(summm[x.y] < summm[y.y]) return 1;
        return 0;
    }
    return 0;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int ans = 0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        memset(L,0,sizeof(L));
        cin>>n;
        int tnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= 3;j++) {
                cin>>a[i][j];tnt++;
                summm[j] += a[i][j];
                d[tnt].x = i;
                d[tnt].y = j;

            }
        }
        for(int i = 1;i <= n;i++) {
            d[3*(i-1)+1].sx = a[i][1]-a[i][2]-a[i][3];
            d[3*(i-1)+2].sx = a[i][2]-a[i][1]-a[i][3];
            d[3*(i-1)+3].sx = a[i][3]-a[i][2]-a[i][1];
        }
        sort(d+1,d+tnt+1,cmp);
        int lgg = 0;
        for(int i = 1;i;i++) {
            if(!vis[d[i].x] && L[d[i].y] < n/2) {
                ans += a[d[i].x][d[i].y];
                L[d[i].y]++;
                vis[d[i].x] = 1;
                lgg++;
            }
            if(lgg == n) break;
        }
        cout<<ans<<endl;
    }

    return 0;
}
