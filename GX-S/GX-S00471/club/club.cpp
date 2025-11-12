#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5+5;
int a[maxn][4];
int c[5];
long long ans = 0;

void dfs(int pos, long long cnt){
    if(pos > n){
        ans = max(cnt, ans);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(c[i] >= n/2) continue;
        cnt += a[pos][i];
        c[i] ++;
        dfs(pos+1, cnt);
        cnt -= a[pos][i];
        c[i] --;
    }
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(c, 0 ,sizeof(c));
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        }
        dfs(1, 0);
        printf("%lld\n", ans);
    }

    return 0;
}
