#include<bits/stdc++.h>
using namespace std;
int n,m,k,nl[2001][2001][1001],val[1001],queuenum[1002],total;

void dfs(int x){

    int tmpnum=0x7ffffff,tmpper=0;
    for(int i=1;i<=n;i++){
        if(i==x)continue;
        for(int j=0;j<=k;j++){
            if(nl[x][i][j]<tmpnum){
                tmpnum=nl[x][i][j];
                tmpper=i;
            }
        }
    }
    total=tmpnum;
    for(int i=2;queuenum[i]!=1;i++){
        if(queuenum[i]==0){
            queuenum[i]=tmpper;
            dfs(tmpper);
        }
    }

}
void way(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            nl[i][j][x]=nl[1000+x][i][0]+nl[1000+x][j][0]+val[x];
        }
    }
}


int main(){
    freopen("road.in","rb",stdin);
    freopen("road.out","wb",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,p,q;i<=m;i++){
        scanf("%d%d",&p,&q);
        scanf("%d",&nl[p][q][0]);
        nl[q][p][0]=nl[p][q][0];
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&val[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&nl[1000+i][j][0]);
            nl[j][1000+i][0]=nl[1000+i][j][0];
        }
    }
    for(int i=1;i<=k;i++){
        way(i);
    }
    queuenum[1]=1;
    dfs(1);
    printf("%d",total);
    return 0;
}
