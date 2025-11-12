#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#define ll long long
string s;
int a[505],ans[505],vis[505],dp[505][505];
int n,m,an = 0;
void dfs(int x){
    if(x == n){
        int sum = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                sum++;
                continue;
            }if(a[ans[i]]<=sum){
                sum++;
            }
        }
        if(sum <= n-m){
            an++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans[x] = i;
            vis[i] = 1;
            dfs(x+1);
            vis[i] = 0;
        }
    }
}
int main(){
    #ifdef LOCAL
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    #endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<an<<endl;
}
