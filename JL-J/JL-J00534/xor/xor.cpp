#include<bits/stdc++.h>
using namesapce std;
int n,k,a[500005],vis[500005],cnt,ans;

void dfs(int id){
    if(id == n+1){
        ans++;
        return 0;
    }

    if(vis[id] == 0){
        vis[id] = 1;
        cnt = cnt^a[id];
        dfs(id+1);
    }
    vis[id] = 0;
    cnt = cnt^a[id];
    dfs(id+1);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cnt = a[1];
    dfs(2);
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}