#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,1};
void dfs(int x,int y,int l,int k){
    if(l>n*m){
        return;
    }
    a[x][y]=l;
    if(k==1||k==3){
        k++;
        k%=4;
    }
    int nx=x+dx[k],ny=y+dy[k];
    if(nx<=n&&ny<=m&&nx>=1&&ny>=1){
        dfs(nx,ny,l+1,k);
        return;
    }
    k++;
    nx=x+dx[k],ny=y+dy[k];
    if(nx<=n&&ny<=m&&nx>=1&&ny>=1){
        dfs(nx,ny,l+1,k);
        return;
    }
}
struct node{
    int l1,l2;
}b[1005];
bool cmp(node k1,node k2){
    return k1.l1>k2.l1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    dfs(1,1,1,0);
    for(int i=1;i<=n*m;i++){
        cin>>b[i].l1;
        b[i].l2=i;
    }
    sort(b+1,b+1+n*m,cmp);
    int u=0;
    for(int i=1;i<=n*m;i++){
        if(b[i].l2==1){
            u=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==u){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
