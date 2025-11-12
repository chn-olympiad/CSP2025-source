#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][3];
int ans=0;
int res[100005];
int now[100005];
void dfs(int u,int v,int x,int y,int z){
    if(u==n+1){
        ans=max(ans,v);
        if(ans==v){
            for(int i=1;i<=n;i++){
                res[i]=now[i];
            }
        }
        return;
    }
    if(x!=n/2){
        now[u]=1;
        dfs(u+1,v+a[u][1],x+1,y,z);
    }
    if(y!=n/2){
        now[u]=2;
        dfs(u+1,v+a[u][2],x,y+1,z);
    }
    if(z!=n/2){
        now[u]=3;
        dfs(u+1,v+a[u][3],x,y,z+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        ans=0;
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
/*
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

10
4 21 29
6 23 25
3 13 24
5 17 30
14 18 11
8 22 28
12 20 27
15 1 9
2 7 16
26 10 19
*/
