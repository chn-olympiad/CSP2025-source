#include<bits/stdc++.h>
using namespace std;
int fx[]={0,1,-1,0,0};
int fy[]={0,0,0,1,-1};
int n,m,c,r,z,p=2;
int a[1000][1000],k[100000];
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int y){
    int tx,ty;
    for(int i=1;i<=4;i++){
        tx=x+fx[i];
        ty=y+fy[i];
        if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]==0){
            a[tx][ty]=k[p];
            p++;
            dfs(tx,ty);
        }

    }
}
int main(){
    freopen("seat.in","r",stdin);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>k[i];
    z=k[1];
    sort(k+1,k+n*m+1,cmp);
    a[1][1]=k[1];
    dfs(1,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==z){
                cout<<j<<" "<<i;
                exit(0);
            }
    freopen("seat.out","w",stdout);
    return 0;
}
