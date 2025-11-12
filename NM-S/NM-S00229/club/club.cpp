#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],ans;
inlive void dfs(int a,int b,int c,int x,int i){
    if(a + b + c == n){
        ans = max(ans,x);
        return;
    }
    if(a < n / 2)
        dfs(a + 1,b,c,x + a[i][1],i + 1);
    if(b < n / 2)
        dfs(a,b + 1,c,x + a[i][2],i + 1);
    if(c < n / 2)
        dfs(a,b,c + 1,x + a[i][3],i + 1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        dfs(0,0,0,0,1);
        printf("%d\n",ans);
        ans = 0;
    }
}
