#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int u[15][15];
int ans;
bool px(int a,int b){
    return a>b;
}
void dg(int dep,int x,int y,bool f){
    if(dep<=n*m){
        u[x][y]=a[dep];
        if(f==1&&y+1>m){
            f=0;
            dg(dep+1,x+1,y,0);
        }else if(f==0&&y-1<=0){
            f=1;
            dg(dep+1,x+1,y,1);
        }else{
            if(f==1){
                dg(dep+1,x,y+1,1);
            }else{
                dg(dep+1,x,y-1,0);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1,px);
    dg(1,1,1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(u[i][j]==ans){
                cout<<i<<' '<<j;
            }
        }
    }

    return 0;
}
