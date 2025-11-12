#include<bits/stdc++.h>
using namespace std;
const int N = 509;
int n,m,c[N];
string s;
int cnt;
bool vis[N];
void dfs(int x,int g){
    if (g > n-m) return;
    if(x == n+1){
        ++cnt;
        return;
    }
    for(int i = 1;i <= n;++i){
        if(vis[i]) continue;
        vis[i] = true;
        if (g >= c[i] || s[x] == '0') dfs(x+1,g+1);
        else dfs(x+1,g);
        vis[i] = false;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin >> s;
    for(int i = 1;i <= n;++i){
        scanf("%d",&c[i]);
    }
    s = " " + s;
    memset(vis,false,sizeof vis);
    dfs(1,0);
    cout << cnt;
    return 0;
}
