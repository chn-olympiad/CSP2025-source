#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000000001;
int n,m,k,arr[10001][10001]={},x,y,w,cc[11],cv[11][10001];
int minc[10001][10001]={},vis1[10001][10001];
void floyd
int mink(int a,int b){
    if(a>=b)return b;
    if(a<=b)return a;
}int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=maxn;
            minc[i][j]=maxn;
        }
    }cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        arr[x][y]=w;
        arr[y][x]=w;
        minc[x][y]=w;
        minc[y][x]=w;
    }for(int i=1;i<=k;i++){
        cin>>cc[i];
        for(int j=1;j<=n;j++){
            cin>>cv[i][j];
        }
    }for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             if(vis1[i][j]==1||i==j)continue;
             for(int g=1;g<=k;g++){
                 minc[i][j]=mink(minc[i][j],cc[g]+cv[g][i]+cv[g][j]);
                 minc[j][i]=minc[i][j];
             }vis1[i][j]=1;
             vis1[j][i]=1;
         }
    }
    floyd(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
