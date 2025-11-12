#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n;
const int mod = 998244353;
int a[N];
int path[N];
bool vis[N];
int ans = 0;
bool check(int num){
    int sum = 0;
    int max_l = 0;
    for(int i=1;i<=num;++i) {
        sum+=path[i];
        max_l = max(max_l,path[i]);
    }
    if(sum>max_l*2) return true;
    else return false;
}
void dfs(int idx,int idx_a,int num){
    if(idx==num+1){
        if(check(num)){
            //for(int i=1;i<=num;++i){
              //  cout<<path[i]<<" ";
            //}
            //cout<<endl;
            ans = (ans+1)%mod;
        }
        return ;
    }
    for(int i=idx_a;i<=n;++i){
        if(vis[i] == false){
            vis[i] = true;
            path[idx] = a[i];
            //cout<<idx<<endl;
            //for(int i=1;i<=n;++i) cout<<vis[i]<<" ";
            //cout<<endl;
            dfs(idx+1,i+1,num);
            vis[i] = false;
        }
    }
}
void sovle(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int sum = 0;
    for(int i=3;i<=n;++i){
        memset(vis,false,sizeof(vis));
        memset(path,0,sizeof(path));
        ans = 0;
        dfs(1,1,i);
        sum+=ans;
    }
    cout<<sum;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 1;
    while(N--) sovle();
    return 0;
}
