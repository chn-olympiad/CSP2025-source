#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int ans,n,a[5010];
bool vis[5010];

void dfs(int x,int y,int cnt,int mini){
    cnt++;
    if(x > 2*y && cnt >= 3) ans++;
    for(int i = mini;i < n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        dfs(x+a[i],max(y,a[i]),cnt,i);
        vis[i]=false;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n,0);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,-1,0,0);
    printf("%d",ans%MOD);
    return 0;
}
