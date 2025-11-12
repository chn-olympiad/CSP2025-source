#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
int t,n,ans;
int a[maxn][4];
int nmember[4];
bool flag[maxn];
void dfs(int x,int c,int s){
    if(flag[x])return;
    if(c==1){
        dfs(x,2,s);
        dfs(x,3,s);
    }
    if(nmember[c]>=(n/2))return;
    nmember[c]++;
    s+=a[x][c];
    if(x==n){
        ans=max(ans,s);
        nmember[c]--;
        return;
    }
    flag[x]=1;
    dfs(x+1,1,s);
    nmember[c]--;
    flag[x]=0;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(nmember,0,sizeof(nmember));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }
        dfs(1,1,0);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}