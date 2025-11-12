#include <bits/stdc++.h>
using namespace std;
struct city{
    int money;
    bool isbuild=false;
}c[100];
int n,m,k;
int v[10020][10020];
int w[10020];
int ans=0;
void dfs(int num,int money){
        bool t=true;
        for(int i=1;i<=n;i++){
            if(!w[i]){
                t=false;
            }
        }
        if(t){
            ans=max(ans,money);
            return;
        }
        for(int i=1;i<=n+k;i++){
            if(v[num][i]>0&&!v[i]){
                if(i<=n){
                    w[i]=1;
                    dfs(i,money+v[num][i]);
                    w[i]=0;
                }else{
                    if(c[i-n].isbuild){
                        dfs(i,money+v[num][i]);
                    }else{
                        c[i-n].isbuild=true;
                        dfs(i,money+c[i-n].money+v[num][i]);
                        c[i-n].isbuild=false;
                    }

                }
            }
        }
    }
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x][y]=z;
        v[y][x]=z;
    }
    for(int i=1;i<=k;i++){
        int a;
        cin>>a;
        c[i].money=a;
        for(int j=1;j<=n;j++){
            int b;
            cin>>b;
            v[i][n+k]=b;
            v[n+k][i]=b;
        }
    }
    w[1]=1;
    dfs(1,0);
    cout<<ans;
    return 0;
}
