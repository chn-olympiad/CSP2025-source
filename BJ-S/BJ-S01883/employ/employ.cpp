#include <bits/stdc++.h>
using namespace std;
int a[20],f[20];
int n,m,ans;string s;
void check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cnt<f[i] && s[i-1]=='1'){
            cnt++;
        }
    }
    ans+=(cnt>=m);
    return;
}
void dfs(int x){
    if(x==n+1){
        check();return;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=a[x];dfs(x+1);f[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}