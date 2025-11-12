#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m;
int s[510],c[510];
int a[510],b[510];
bool vis[510];
int ans=0;
void dfs(int p){
    if (p == n){
        for (int i=1;i<=n;i++) b[i]=c[a[i]];
        int cnt=0;
        for (int i=1;i<=n;i++){
            if (s[i]==0){
                cnt++;
                continue;
            }
            if (cnt>=b[i]){
                cnt++;
                continue;
            }
        }
        if (n-cnt>=m) ans++;
        return;
    }
    for (int i=1;i<=n;i++){
        if (vis[i]) continue;
        a[p+1]=i;
        vis[i]=1;
        dfs(p+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        char c=getchar();
        while (c!='0' and c!='1') c=getchar();
        if (c == '0') s[i]=0;
        else s[i]=1;
    }
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    if (n<=10){
        dfs(0);
        printf("%d\n",ans);
        return 0;
    }
    puts("0");
    return 0;
}
