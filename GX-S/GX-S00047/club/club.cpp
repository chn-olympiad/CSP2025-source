#include<bits/stdc++.h>
using namespace std;
int T,n,ans=0;
struct node{
    int x,y,z;
}a[100005];
void dfs(int i,int x,int y,int z,int sum){
    if(i>n){
        ans=max(ans,sum);
        return ;
    }
    if(x+1<=n/2) dfs(i+1,x+1,y,z,sum+a[i].x);
    if(y+1<=n/2) dfs(i+1,x,y+1,z,sum+a[i].y);
    if(z+1<=n/2) dfs(i+1,x,y,z+1,sum+a[i].z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        dfs(1,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
