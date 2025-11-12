#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
struct node{
    int x,y;
}t[10010];
int b[10010];
bool in(int x,int y){
    return x>=1&&x<=m&&y>=1&&y<=n;
}
void dfs(int x,int y,int now){
    t[a[now]]={x,y};
    if(now==n*m-1){
        return;
    }else{
        if(x%2==1&&in(x,y)){
            if(y==n){
                dfs(x+1,y,now+1);
            }else{
                dfs(x,y+1,now+1);
            }
        }else if(x%2==0&&in(x,y)){
            if(y==1){
                dfs(x+1,y,now+1);
            }else{
                dfs(x,y-1,now+1);
            }
        }
    }
    return;
}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n*m);
    reverse(a,a+n*m);
    dfs(1,1,0);
    cout<<t[b[0]].x<<" "<<t[b[0]].y;
    return 0;
}
