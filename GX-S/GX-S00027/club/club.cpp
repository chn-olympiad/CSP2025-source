#include<bits/stdc++.h>
using namespace std;
int t,n,a[10001][4],ans;




void dfs(int x,int y,int z,int c){
    if(n==x+y+z){
        if(ans<c)ans=c;
        return;
    }
    if(x<n/2)dfs(x+1,y,z,c+a[x+y+z+1][1]);
    if(y<n/2)dfs(x,y+1,z,c+a[x+y+z+1][2]);
    if(z<n/2)dfs(x,y,z+1,c+a[x+y+z+1][3]);
}
int main(){
    freopen("club.in","rb",stdin);
    freopen("club.out","wb",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
        }
       dfs(0,0,0,0);
       printf("%d\n",ans);
       ans=0;
    }
    return 0;
}
