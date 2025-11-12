#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define int long long
int n;
int d[MAXN][3];
int maxwei[MAXN];
int b[MAXN];
void solve()
{
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++) scanf("%lld%lld%lld",&d[i][0],&d[i][1],&d[i][2]);
    for(int i = 1; i <= n; i++){
        if(d[i][0] >= d[i][1] && d[i][0] >= d[i][2]) maxwei[i] = 1;
        else if(d[i][1] >= d[i][0] && d[i][1] >= d[i][2]) maxwei[i] = 2;
        else maxwei[i] = 3;
    }
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    for(int i = 1; i <= n; i++){
        if(maxwei[i] == 1) cnt1++;
        if(maxwei[i] == 2) cnt2++;
        if(maxwei[i] == 3) cnt3++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = ans + d[i][maxwei[i] - 1];
    if(cnt1 > n/2){
        int num = 0;
        for(int i = 1; i <= n; i++){
            if(maxwei[i] == 1) num++,b[num] = min(d[i][0] - d[i][1],d[i][0] - d[i][2]);
        }
        sort(b+1,b+num+1);
        for(int i = 1; i <= cnt1 - n/2; i++) ans = ans - b[i];
    }else if(cnt2 > n/2){
        int num = 0;
        for(int i = 1; i <= n; i++){
            if(maxwei[i] == 2) num++,b[num] = min(d[i][1] - d[i][0],d[i][1] - d[i][2]);
        }
        sort(b+1,b+num+1);
        for(int i = 1; i <= cnt2 - n/2; i++) ans = ans - b[i];
    }else if(cnt3 > n/2){
        int num = 0;
        for(int i = 1; i <= n; i++){
            if(maxwei[i] == 3) num++,b[num] = min(d[i][2] - d[i][1],d[i][2] - d[i][0]);
        }
        sort(b+1,b+num+1);
        for(int i = 1; i <= cnt3 - n/2; i++) ans = ans - b[i];
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; scanf("%lld",&t);
    while(t--) solve();
    return 0;
}