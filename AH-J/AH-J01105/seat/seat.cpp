#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};int m=0,n=0,t=0;
long long nm[101][101],a[2];
void dfs(int x,int y,int k){
    nm[x][y]=k;
    if(k!=0)
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(nm[a][b]==0&&a>=0&&b>=0&&a<n&&b<n){
                dfs(a,b,k-1);
            }
        }
    else{
        cout<<y+1<<" "<<x+1<<endl;
        exit(0);
    }
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    cin>>a[0];
    for(int i=1;i<n*m;i++){
        cin>>a[1];
        if(a[1]>a[0]) t++;
    }
    dfs(0,0,t);
    return 0;
}
