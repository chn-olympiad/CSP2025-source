#include <cstdio>
#include <algorithm>
using namespace std;
int tt,n,a[1005][5],t[1005],ans;
void dfs(int dep,int tmp,int t1,int t2,int t3){
    if(t1>n/2||t2>n/2||t3>n/2||t1+t2+t3>n){
        return;
    }else if(dep==n+1){
        ans = max(tmp,ans);
        return;
    }else{
        dfs(dep+1,tmp+a[dep][1],t1+1,t2,t3);
        dfs(dep+1,tmp+a[dep][2],t1,t2+1,t3);
        dfs(dep+1,tmp+a[dep][3],t1,t2,t3+1);
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&tt);
    while(tt--){
        ans = 0;
        scanf("%d",&n);
        int isA = 1;
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][2]!=0||a[i][3]!=0){isA = 0;}
        }
        if(isA){
            for(int i = 1;i <= n;i++){
                t[i] = a[1][i];   
            }
            sort(t+1,t+n+1);
            for(int i = 1;i <= n/2;i++){ans += t[i];}
        }
        else{dfs(1,0,0,0,0);}
        printf("%d\n",ans);
    }
    return 0;
}