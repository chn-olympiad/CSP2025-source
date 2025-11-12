#include<bits/stdc++.h>
using namespace std;
const int N=505;
char s[N];
int n,m,ans;
int c[N],p[N];
bool vis[N];
void dfs(int x){
    if(x>n){
        int cnt=n;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')cnt--;
            else{
                if(c[p[i]]<=n-cnt)cnt--;
            }
        }
        if(cnt>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            p[x]=i;
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
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(1);
    printf("%d\n",ans);

    return 0;
}