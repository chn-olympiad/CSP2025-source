#include<bits/stdc++.h>
using namespace std;

int n,m;
struct info{
    int v,id;
}a[105];
int ans[15][15];

bool cmp(info A,info B){
    return A.v>B.v;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].v);
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1;
    bool dir=0;
    //0 down 1 up
    for(int t=1;t<=n*m;t++){
        ans[x][y]=a[t].id;
        int nx=x,ny=y;
        if(dir) nx=x-1;
        else nx=x+1;
        if(nx<1){
            nx=1,ny=y+1;
            dir=!dir;
        }else if(nx>n){
            nx=n,ny=y+1;
            dir=!dir;
        }
        x=nx,y=ny;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==1){
                printf("%d %d\n",j,i);
                return 0;
            }
        }
    }
    return 0;
}
