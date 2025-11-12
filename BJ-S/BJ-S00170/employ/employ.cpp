#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n, m;
char ss[510];
int s[510], c[510];
int dl[510], t;
int vis[510];
long long anss=0;
void ck(){
    int goo=0, gett=0;
    for(int i=1;i<=n;i++){
        if(goo>=c[dl[i]]||s[i]==0){
            goo++;
        }else{
            gett++;
        }
    }
    if(gett>=m){
        anss++;
        anss%=MOD;
    }
}
void dfs(int x, int dep){
    if(dep==n){
        ck();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dl[++t]=i;
            dfs(i, dep+1);
            t--;
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m>>ss;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=(int)(ss[i-1]-'0');
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            vis[i]=1;
            dl[++t]=i;
            dfs(i, 1);
            t--;
            vis[i]=0;
        }
        cout<<anss;
    }else{
        cout<<0;
    }
    return 0;
}