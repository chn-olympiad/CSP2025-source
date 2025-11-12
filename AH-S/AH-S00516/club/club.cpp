#include<stdio.h>
#include<string.h>
#define mx(i,j) ((i)>(j)?(i):(j))
int a[100002][4],n,t,ans;
int dfs(int i,int j,int n1,int n2,int n3) {
    if(n1>n/2||n2>n/2||n3>n/2)return 0;
    if(i>n)return 0;
    return mx(mx(dfs(i+1,1,n1+1,n2,n3),dfs(i+1,2,n1,n2+1,n3)),dfs(i+1,3,n1,n2,n3+1))+a[i][j];
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        ans=mx(dfs(1,1,1,0,0),mx(dfs(1,2,0,1,0),dfs(1,3,0,0,1)));
        printf("%d\n",ans);
    }
    return 0;
}
