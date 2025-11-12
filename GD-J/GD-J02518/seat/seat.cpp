#include<bits/stdc++.h>
using namespace std;
int st1[3]={1,-1,0},st2[3]={0,0,1},vis1[11][11],vis2[11][11],a[101];
int stx(int x,int y,int q){
    if(q==0) return x;
    if(vis1[x+st1[0]][y+st2[0]]==1){
        vis1[x][y]=2;
        return stx(x+st1[0],y+st2[0],q-1);
    }
    if(vis1[x+st1[1]][y+st2[1]]==1){
        vis1[x][y]=2;
        return stx(x+st1[1],y+st2[1],q-1);
    }
    if(vis1[x+st1[2]][y+st2[2]]==1){
        vis1[x][y]=2;
        return stx(x+st1[2],y+st2[2],q-1);
    }
}
int sty(int x,int y,int q){
    if(q==0) return y;
    if(vis2[x+st1[0]][y+st2[0]]==1){
        vis2[x][y]=2;
        return sty(x+st1[0],y+st2[0],q-1);
    }
    if(vis2[x+st1[1]][y+st2[1]]==1){
        vis2[x][y]=2;
        return sty(x+st1[1],y+st2[1],q-1);
    }
    if(vis2[x+st1[2]][y+st2[2]]==1){
        vis2[x][y]=2;
        return sty(x+st1[2],y+st2[2],q-1);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p=n*m,w=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis1[i][j]=1;
            vis2[i][j]=1;
        }
    }
    for(int i=1;i<=p-1;i++){
        for(int j=1;j<=p-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=p;i++){
        if(a[i]==R){
            w=i;
        }
    }
    cout<<sty(1,1,w-1)<<" "<<stx(1,1,w-1);
    return 0;
}

