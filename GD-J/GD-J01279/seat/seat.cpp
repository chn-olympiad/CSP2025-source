#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t[15][15];
bool cmp(int x,int y){return x>y;}
void dfs(int x,int y,int v,int w){
    if(y>m)return;
    t[x][y]=a[v];
    if(w==0){
        if(x>=n)dfs(x,y+1,v+1,1);
        else dfs(x+1,y,v+1,0);
    }else{
        if(x<=1)dfs(x,y+1,v+1,0);
        else dfs(x-1,y,v+1,1);
    }
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];
    int x=a[1];
    sort(a+1,a+1+n*m,cmp);
    dfs(1,1,1,0);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(t[i][j]==x){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
