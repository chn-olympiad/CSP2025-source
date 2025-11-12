#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],s[20][20];
bool cmp(int a,int b){
    return a>b;
}
void dfs(int i,int d,int x,int y){
    if(i==n*m+1){
        return;
    }
    if(d==1){
        if(x+1<=n){
            s[x+1][y]=a[i];
            dfs(i+1,d,x+1,y);
        }else{
            s[x][y+1]=a[i];
            dfs(i+1,2,x,y+1);
        }
    }
    if(d==2){
        if(x==n){
            s[x-1][y]==a[i];
            dfs(i+1,3,x-1,y);
        }else{
            s[x+1][y]==a[i];
            dfs(i+1,1,x+1,y);
        }
    }
    if(d==3){
        if(x-1>=1){
            s[x-1][y]=a[i];
            dfs(i+1,d,x-1,y);
        }else{
            s[x][y+1]=a[i];
            dfs(i+1,2,x,y+1);
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+n*m+1,cmp);
    s[1][1]=a[1];
    dfs(2,1,1,1);//x 1;y 2;s 3
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==p){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
