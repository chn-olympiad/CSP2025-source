#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[501],b[501],a[501],ans;
char s[501];
void dfs(int u,int sum,int ct){
    if(u>n){
        if(sum>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!a[i]){
            a[i]=1;
            if(c[i]<=ct) dfs(u+1,sum,ct+1);
            else if(s[u]=='0') dfs(u+1,sum,ct+1);
            else dfs(u+1,sum+1,ct);
            a[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1,0,0);
    cout<<ans;
}
