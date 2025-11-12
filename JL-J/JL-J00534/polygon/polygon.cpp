#include<bits/stdc++.h>
using namesapce std;
int n,a[5005],vis[5005],sum,cnt,ans,m;
int check(){
    ans = a[n];
    sum = cnt = 0;
    for(int i = 1;i <= ans;i++){
        if(vis[i]){
            sum += vis[i];
            cnt += i;
        }
    }
    if(sum >= 3 and cnt > ans*2){
        return 1;
    }
    return 0;
}
void dfs(int id){
    if(id == n+1){
        if(check()){
            m++;
        }
        return ;
    }

    vis[id] += 1;
    dfs(id+1);
    vis[id] -= 1;
    dfs(id+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a);
    dfs(1);
    cout << m << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}