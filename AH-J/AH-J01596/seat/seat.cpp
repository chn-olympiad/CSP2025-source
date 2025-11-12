#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],pos,ansx,ansy;
bool flag;
void dfs(int x,int y,string s,int t){
    if(flag) return ;
    if(a[t]==pos) {
        ansx=x;
        ansy=y;
        flag=true;
        return ;
    }
    if(x==n&&y==m){
        return ;
    }
    if(s=="down"){
        if(x+1<=n) dfs(x+1,y,"down",t+1);
        else if(y+1<=m) dfs(x,y+1,"right",t+1);
    }else if(s=="up"){
        if(x-1>=1) dfs(x-1,y,"up",t+1);
        else if(y+1<=m) dfs(x,y+1,"right",t+1);
    }else if(s=="right"){
        if(x==1) dfs(x+1,y,"down",t+1);
        else dfs(x-1,y,"up",t+1);
    }
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    pos=a[1];
    sort(a+1,a+n*m+1,greater<int>());

    dfs(1,1,"down",1);
    cout<<ansy<<" "<<ansx<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
