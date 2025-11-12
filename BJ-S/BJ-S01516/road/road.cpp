#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct road{
    int u;
    int v;
    int w;
}r[1000001];
int n,m,k,c[11][10001]={},q[6001][6002][11]={};
int cg[10001][10001]={},ans=0,ans1=999999999;
bool check(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!cg[i][j])
                return 0;
        }
    }
    return 1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>r[i].v>>r[i].u>>r[i].w;
        q[r[i].v][r[i].u][0]=q[r[i].u][r[i].v][0]=r[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i][0];
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int r=1;r<=k;r++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                q[i][j][r]=q[j][i][r]=c[r][i]+c[r][j];
            }
        }
    }
    for(int d=0;d<=k;d++){
        ans=c[d][0];
        while(!check()){
            int mi=1000001,u,v;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(!cg[i][j]&&mi>min(q[i][j][0],q[i][j][d])){
                        mi=min(mi,min(q[i][j][0],q[i][j][d]));
                        u=i;
                        v=j;
                    }

                }
            }
            cg[u][v]=cg[v][u]=1;
            for(int i=1;i<=n;i++){
                if(cg[u][i]){
                    cg[v][i]=1;
                }
                if(cg[v][i]){
                    cg[u][i]=1;
                }
            }
            ans+=mi;
        }
        memset(cg,0,sizeof(cg));
        ans1=min(ans,ans1);
    }
    cout<<ans1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
