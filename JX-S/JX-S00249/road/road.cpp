#include<bits/stdc++.h>
using namespace std;
int n,m,k,an;
int path[1000001][4];
int cc[10];
int cp[10][10001];
int fa[100001];
int son[100001];
int fin(int k){
    if(fa[k]==k) return k;
    else return fin(fa[k]);
}
int built(int k){
    fa[path[k][2]]=fin(path[k][1]);
    son[fin(path[k][1])]+=son[path[k][2]];//son[1]==n
    return path[k][3];
}
int dfs(int cnt,int k){
    if(k>m) return INT_MAX;
    if(son[1]==n) return cnt;
    cnt+=min(built(k),dfs(cnt,k+1));

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>path[i][1]>>path[i][2]>>path[i][3];
        if(path[i][1]>path[i][2]) swap(path[i][1],path[i][2]);
    }
    for(int i=1;i<=k;i++){
        cin>>cc[i];
        for(int j=1;j<=n;j++){
            cin>>cp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
        son[i]=1;
    }
    an=dfs(0,1);
    cout<<an;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
