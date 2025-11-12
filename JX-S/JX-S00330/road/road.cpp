#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,sum=0,k,mtx[1035][1035],a[1035][1035],sza[1035];
int pr[1025];
//vector<vector<int>>mtx;
void dfs(int p,int cst,int lp){
    if(pr[p]>cst){
        pr[p]=cst;
        int lon=sza[lp];
        for(int i=1;i<=lon;i++) a[p][i]=a[lp][i];
        sza[p]=lon;
        a[p][sza[p]+1]=p;
        sza[p]++;
    }
    
    for(int i=1;i<=n+k;i++){
        if(mtx[p][i]>=0&&mtx[p][i]==mtx[i][p]){
            mtx[p][i]=-abs(mtx[p][i]);
            mtx[i][p]=mtx[p][i];
            dfs(i,cst-mtx[p][i],p);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    
    for(int i=0;i<=n+k;i++){
        pr[i]=INT_MAX/2-1145;
        for(int j=0;j<=n+k;j++) mtx[i][j]=-1;
    }
    
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        mtx[x][y]=z;
        mtx[y][x]=z;
    }
    
    for(int i=n+1;i<=n+k;i++){
        for(int j=1;j<=n;j++){
            cin>>z;
            mtx[i][j]=z;
            mtx[j][i]=z;
        }
    }
    
//    dfs(1,0,1);
    
    for(int i=1;i<=n;i++){
        int llon=sza[i];
        for(int j=2;j<=llon;j++) mtx[a[i][j]][a[i][j-1]]=abs(mtx[a[i][j]][a[i][j-1]]);
    }
    for(int i=1;i<=n+k;i++){
        for(int j=1;j<=n+k;j++){
            if(mtx[i][j]==mtx[j][i]*-1) sum+=abs(mtx[i][j]);
        }
    }
    cout<<sum;
    
    return 0;
}