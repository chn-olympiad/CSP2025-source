#include <bits/stdc++.h>
using namespace std;
int maps[10086][10086],n,m,f,a[10086][10086],bj[10086][10086],ai[10086],zz[10086][10086];
int ak(int nn){
    int ac=0;
    for(int i=1;i<=nn;i++){
        maps[i][i]=1;
    }
    for(int i=1;i<=nn;i++){
        for(int k=1;k<=nn;k++){
            for(int j=i+1;j<=nn;j++){
                if(maps[i][j]==1 and (maps[i][k]==1 and maps[k][j]==1)){
                    a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[k][j]);
                    if(i==1) zz[1][j]=1;
                    if(zz[1][k]==1 and (i==1 or j==1)) bj[i][j]=bj[j][i]=1;
                }
                else if(maps[i][j]==0 and (maps[i][k]==1 and maps[k][j]==1)){
                    maps[i][j]=maps[j][i]=1;
                    a[i][j]=a[i][k]+a[k][j];
                    if(i==1) zz[1][j]=1;
                    if(zz[1][k]==0) bj[i][j]=bj[j][i]=1;
                }
            }
        }
    }
    for(int i=1;i<=nn;i++){
        for(int k=1;k<=nn;k++){
            for(int j=i+1;j<=nn;j++){
                if(maps[i][j]==1 and (maps[i][k]==1 and maps[k][j]==1)){
                    a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[k][j]);
                    if(i==1) zz[1][j]=1;
                    if(zz[1][k]==1 and ((i==nn or j==nn))) bj[i][j]=bj[j][i]=1;
                }
                else if(maps[i][j]==0 and (maps[i][k]==1 and maps[k][j]==1)){
                    maps[i][j]=maps[j][i]=1;
                    a[i][j]=a[i][k]+a[k][j];
                    if(i==1) zz[1][j]=1;
                    if(zz[1][k]==0) bj[i][j]=bj[j][i]=1;
                }
            }
        }
    }
    for(int i=2;i<=nn;i++){
        if(bj[1][i]==1)ac+=a[1][i];
        if(a[i][1]==0) ac=1e9;
    }
    return ac;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>f;
    int ans=0,anss=0;
    for(int i=1;i<=m;i++){
        int x,y,j;
        cin>>x>>y>>j;
        maps[x][y]=maps[y][x]=1;
        a[x][y]=a[y][x]=j;
    }
        ans=ak(n);
    for(int i=1;i<=f;i++){
        cin>>ai[i];
        anss+=ai[i];
        int x,y;
        for(int j=1;j<=n;j++){
            cin>>y;
            maps[n+i][j]=maps[j][n+i]=1;
            a[n+i][j]=a[j][n+i]=y;
        }
        anss+=ak(n+i);
        ans=min(ans,anss);
    }
    cout<<ans<<endl;
    return 0;
}
