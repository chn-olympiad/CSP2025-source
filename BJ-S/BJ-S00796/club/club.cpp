#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N][4];
int b[N];
int ans;
void dfs(int u){
    if(u == n + 1){
        int sum = 0;
        int cnt[4];
        cnt[1] = cnt[2] = cnt[3] = 0;
        for(int i=1;i<=n;i++){
            sum += a[i][b[i]];
            cnt[b[i]]++;
        }
        for(int i=1;i<=3;i++){
            if(cnt[i] > n/2) return ;
        }
        ans = max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        b[u] = i;
        dfs(u + 1);
    }
}
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T -- ){
        ans = 0;
        scanf("%d",&n);
        bool flag2 = true,flag3 = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }
            if(a[i][2]) flag2 = false;
            if(a[i][3]) flag3 = false;
        }
        if(n <= 10){
            dfs(1);
            printf("%d\n",ans);
            continue;
        }
        if(flag2 && flag3){
            for(int i=1;i<=n;i++) b[i] = a[i][1];
            sort(b + 1,b + n + 1,cmp);
            for(int i=1;i<=n/2;i++) ans += b[i];
            printf("%d\n",ans);
            continue;
        }
        
    }
    return 0;
}
