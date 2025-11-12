#include<bits/stdc++.h>
using namespace std;
int u[1010],v[1010],w[1010],c[1010],a[1010];
int n,m,k;
int cnt=0;
int dfs(int shunxu,bool x,int score,int fy){
    if(score==n){
        cnt=max(cnt,fy);
        return fy;
    }
    dfs(shunxu+1,false,score,fy);
    dfs(shunxu+1,true,score+1,fy+w[shunxu]);
    return fy;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n,m,k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=n+1;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i];
        }
    }
    cout<<max(dfs(1,true,0,w[1]),dfs(1,false,0,0));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
