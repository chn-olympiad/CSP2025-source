#include <bits/stdc++.h>
using namespace std;
int X=10e6+10;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int road[m+1][4];
    for(int i=1;i<=m;i++){
        cin>>road[i][1]>>road[i][2]>>road[i][3];
    }
    int fin[n+1];
    int cstu[k+1];
    int cstr[k+1][n+1];
    for(int i=1;i<=k;i++){
        cin>>cstu[i];
        for(int j=1;j<=n;j++){
            cin>>cstr[i][j];
            fin[i]=0;
        }
    }
    int fg=0;
    int ans=0;
    int vis[n+1];
    for(int i=1;i<=n;i++){
        int cnt=X;
        if(fin[i]){
            continue;
        }
        for(int j=1;j<=m;j++){
            if(road[j][1]==i||road[j][2]==i){
                if(cnt<road[j][3]){
                    cnt=road[j][3];
                    fg=j;
                }
            }
        }
        for(int j=0;j<=k;j++){
            for(int l=0;l<=n;l++){
                if(i==l){
                    continue;
                }
                if(!(vis[l])){
                        cnt+=cstu[j];
                }
                if(cnt<cstr[j][i]+cstr[j][l]){
                    fg=0;
                    cnt=cstr[j][i]+cstr[j][l];
                }else{
                    cnt-=cstu[j];
                }
            }
        }
        fin[fg]=1;
        ans+=cnt;
    }
    cout<<ans;
    return 0;
}
