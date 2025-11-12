#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n, m, s[505], c[505], vis[505];
ll ans;

void dfs(int d, int k){
    if(d>n){
        if(n-k>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            if(s[d]&&c[i]>k) dfs(d+1, k);
            else dfs(d+1, k+1);
            vis[i]=0;
        }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    int f=1, g=1;
    for(int i=1;i<=n;i++){
        scanf("%1d", &s[i]);
        if(s[i]==0) f=0;
        if(s[i]==1) g=0;
    }
    int p=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0) p++;
    }
    if(m==1&&(g||p==n)){
        cout<<0<<endl;
        return 0;
    }
    if(n==m&&(!f||p)){
        cout<<0<<endl;
        return 0;
    }
    dfs(1, 0);
    cout<<ans<<endl;
    return 0;
}
