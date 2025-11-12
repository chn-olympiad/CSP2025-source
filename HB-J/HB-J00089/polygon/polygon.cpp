#include<bits/stdc++.h>
using namespace std;
#define MAXN 5010
int n,arr[MAXN],m,vis[MAXN],h[MAXN],ans;
int check(){
    int sum=0;
    for(int i=1;i<m;i++) sum+=arr[h[i]];
    if(sum>arr[h[m]]) return 1;
    else return 0;
}
void dfs(int r,int last){
    h[r]=last;
    if(r>=m){
        if(check()==1) ans++;
        return;
    }
    for(int i=last+1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(r+1,i);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++){
        m=i;
        dfs(0,0);
    }
    printf("%lld",ans);
    return 0;
}
