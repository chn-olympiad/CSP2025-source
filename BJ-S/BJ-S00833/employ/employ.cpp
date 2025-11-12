#include<bits/stdc++.h>
using namespace std;
int n,m,b[505],ans;
int p[505],num;
char a[505];
bool vis[505];
void dfs(int x){
    if(x>n){
        num=0;
        if(num>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            p[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
            p[x]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    dfs(1);
    printf("%d",ans);
}
