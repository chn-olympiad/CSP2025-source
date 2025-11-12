#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
string s;
int a[N],tot;
int ans[N],vis[N];
void dfs(int x){
    if(x==n+1){
        int sum=0,la=0;
        for(int i=1;i<=n;i++){
            if(i-la>a[ans[i]])continue;
            if(s[i]=='0')la=i;
            else sum++;
        }if(sum>=m)tot++;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        ans[x]=i;
        vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }dfs(1);
    cout<<tot;
    fclose(stdin);
    fclose(stdout);

return 0;
}
