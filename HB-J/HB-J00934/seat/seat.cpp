#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[110],m,n,R;
void dfs(int n,int x,int y){
    if(!a[x][y]){
        a[x][y]=n;
        return ;
    }
    else if(x<m && y%2==1){
        dfs(n,x+1,y);
    }
    else if(x==m && y%2==1){
        dfs(n,x,y+1);
    }
    else if(x>1 && y%2==0){
        dfs(n,x-1,y);
    }
    else if(x==1 && y%2==0){
        dfs(n,x,y+1);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>b[i];
    }
    R=b[1];
    sort(b+1,b+m*n+1);
    for(int i=m*n;i>=1;i--){
        dfs(b[i],1,1);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==R){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
