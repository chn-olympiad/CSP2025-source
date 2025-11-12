#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],px[505],cnt=0,vis[505];
char s[505];
bool check(){
    int mm=0,kc=0;
    for(int i=1;i<=n;i++){
        if(s[i]='0'||c[px[i]]<=kc){
            kc++;
        }else{
            mm++;
        }
    }if(mm>=m){
        return true;
    }else{
        return false;
    }
}
void dfs(int x){
    if(x>n){
        if(check()){
            cnt++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            px[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }for(int i=1;i<=n;i++){
        cin>>c[i];
    }dfs(1);
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}