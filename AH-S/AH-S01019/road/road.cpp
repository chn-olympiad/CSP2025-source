#include<bits/stdc++.h>
using namespace std;
int ink=1000000000;
int n,m,k;
int a[10001][10001]={};
int vis[10001]={};
int minn=ink;
int flag=1;
void bds(int cnt,int wei){
    vis[1]=1;
    if(flag==n){
        minn=min(minn,cnt);
        flag--;
        return;
    }

    //int flag=1;
    for(int i=1;i<=n;i++){
        if(wei!=i&&a[wei][i]!=ink&&vis[i]==0){
            //flag=0
            vis[i]=1;
            flag++;
            bds(cnt+a[wei][i],i);
            vis[i]=0;
            cout<<"flag:"<<flag<<"wei:"<<wei<<" i:"<<i<<" "<<"minn:"<<minn<<endl;
        }

    }
    flag--;
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=a[y][x]=z;
        //vis[x][y]=vis[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){
                a[i][j]=ink;
            }
        }
    }
    vis[1]=1;
    bds(0,1);
    cout<<minn;
    return 0;
}
