#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int ans;
int a[120100];
int n,m;
bool in(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}
bool vis[101][101];
//shang 1  you 2 xia 3
bool dfs(int x,int y,int f,int cnt){
    if(a[cnt]==ans){
        cout<<y+1<<" "<<x+1;
        return 1;
    }
    if(f==1){
        int tx=x-1;
        int ty=y;
        if(in(tx,ty)&&!vis[tx][ty]){
            dfs(tx,ty,f,cnt+1);
        }
        else{
            f=2;
        }
    }
    if(f==3){
        int tx=x+1;
        int ty=y;
        if(in(tx,ty)&&!vis[tx][ty]){
            dfs(tx,ty,f,cnt+1);
        }
        else{
            f=2;
        }
    }
    if(f==2){
        int tx=x;
        int ty=y+1;
        if(in(tx,ty)&&!vis[tx][ty]){
            if(x==n-1)
                dfs(tx,ty,1,cnt+1);
            if(x==0)
                dfs(tx,ty,3,cnt+1);
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	ans=a[0];
	sort(a,a+n*m,cmp);
    dfs(0,0,3,0);
	return 0;
}
