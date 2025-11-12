#include<bits/stdc++.h>
using namespace std;
int n,m,a[11],vis[11],c[11],ans;
string s;
bool check(){
    int lf=0,lo=0;
    for(int i=1;i<=n;i++){
        if(lo>=a[c[i]]){
            lo++;
            continue;
        }
        if(s[i-1]=='1'){
            lf++;
        }
        else {
            lo++;
        }
    }
    if(lf>=m)return true;
    return false;
}
void dfs(int idx){
    if(idx>n){
        if(check()){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            c[idx]=i;
            dfs(idx+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')cnt++;
    }
    if(m>cnt){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
