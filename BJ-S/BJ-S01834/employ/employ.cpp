#include<bits/stdc++.h>
using namespace std;

int a[10000],ans = 0;
string s;
bool vis[1000];
int n,m;
void dfs(int p){
    if(p == n){
        ans++;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(p+1);
            vis[i] = 0;
        }
    }

    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool flag = 1;
    cin>>s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            flag = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    if(flag){
        dfs(1);
        cout<<ans<<endl;
        return 0;
    }

    return 0;
}
