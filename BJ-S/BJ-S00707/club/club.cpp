#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],ans,b[100005];
void dfs(int now,int cnt,int t1,int t2,int t3){
    if(now == n + 1){
        ans = max(ans,cnt);
        return;
    }
    if(t1 < n / 2) dfs(now + 1,cnt + a[now][1],t1 + 1,t2,t3);
    if(t2 < n / 2) dfs(now + 1,cnt + a[now][2],t1,t2 + 1,t3);
    if(t3 < n / 2) dfs(now + 1,cnt + a[now][3],t1,t2,t3 + 1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int tmp = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][2] == a[i][3] && a[i][2] == 0) tmp++;
        }
        ans = 0;
        if(tmp == n){
            for(int i = 1;i <= n;i++) b[i] = a[i][1];
            sort(b + 1,b + n + 1);
            for(int i = n;i >= 1;i--){
                if(n - i + 1 <= n / 2) ans += b[i];
                else break;
            }
            printf("%d\n",ans);
            continue;
        }
        dfs(1,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
