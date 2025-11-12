#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int m,n,b[110][110],a[1000];
void dfs(int cs,int x,int y,int r){
    b[x][y]=a[cs];
    if(x==n&&y==m){
        return;
    }
    if(r==1){
        if(x==n){
            r=0;
            dfs(cs+1,x,y+1,r);
        }else{
            dfs(cs+1,x+1,y,r);
        }
    }else{
        if(x==1){
            r=1;
            dfs(cs+1,x,y+1,r);
        }else{
            dfs(cs+1,x-1,y,r);
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int e=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m*n+1,cmp);
    dfs(1,1,1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==e){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
