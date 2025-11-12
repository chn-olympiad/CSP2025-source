#include<bits/stdc++.h>
#define f for
using namespace std;
int n,m,a[105],s,mx,my,vis[15][15],fx[4]={-1,1,0,0},fy[4]={0,0,-1,1};
bool flag=0;
void input(){
    cin>>m>>n;
    f(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
}
bool in(int x,int y){
    return x>0 and x<=n and y>0 and y<=m; 
}
void dfs(int x,int y,int dep){
    vis[x][y]=1;
    if(dep==s){
        my=y;
        mx=x;
        flag=1;
        return;
    }
    if(flag){
        return;
    }
    f(int i=0;i<4;i++){
        if(flag){
            break;
        }
        int nx=x+fx[i],ny=y+fy[i];
        // printf("%d,%d\n",nx,ny);
        if(!in(nx,ny) or vis[nx][ny]){
            continue;
        }
        // printf("%d,%d\n\n",nx,ny);
        dfs(nx,ny,dep+1);
    }
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    input();
    s=a[1];
    f(int i=1;i<n*m;i++){
        f(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                int x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    f(int i=1;i<=n*m;i++){
        if(a[i]==s){
            s=i;
        }
        // printf("%d ",a[i]);
    }
    // printf("\n%d\n",s);
    //find
    dfs(1,1,1);
    printf("%d %d\n",my,mx);
    return 0;
}