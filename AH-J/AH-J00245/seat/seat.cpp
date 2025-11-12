#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=11,M=1010;
int n,m;
int sc[N][N],a[M];
bool in(int x,int y){
    return (1<=x&&x<=n&&1<=y&&y<=m);
}
int k=0,as;
int ansx,ansy;
void dfs(int x,int y){
    k++;
    sc[x][y]=a[k];
    if(sc[x][y]==as){
        ansx=x;
        ansy=y;
    }else{
        int z;
        if(y%2==1){
            if(in(x+1,y)){
                dfs(x+1,y);
            }else if(in(x,y+1)){
                dfs(x,y+1);
            }
        }else{
            if(in(x-1,y)){
                dfs(x-1,y);
            }else if(in(x,y+1)){
                dfs(x,y+1);
            }
        }


    }
}
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int ln=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    as=a[1];
    sort(a+1,a+1+ln,cmp);
    dfs(1,1);
    cout<<ansy<<" "<<ansx;
    return 0;
}
