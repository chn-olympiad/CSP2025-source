#include<bits/stdc++.h>
using namespace std;
int n,m,se[106],sa[15][15],r;
bool bz[15][15];
int h[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool cmp(int a,int b){
    return a>b;
}

void dfs(int x,int y){
    if(sa[x][y]==r){
        cout << x << " " << y;
        return;
    }

    for(int i=0;i<4;i++){
        int nx=x+h[i][0];
        int ny=y+h[i][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!bz[nx][ny]){
            bz[nx][ny]=true;
            dfs(nx,ny);
        }
    }
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    memset(bz,false,sizeof(bz));
    for(int i=1;i<=n*m;i++){
        cin >> se[i];
        if(i==1) r==se[1];
    }
    sort(se+1,se+n*m+1,cmp);




    int i=1;
    for(int j=1;j<=m;j++){
         if(j%2==1){
            for(int k=1;k<=n;k++){
                sa[k][j]=se[i];
                i++;
            }
         }else{
            for(int k=n;k>=1;k--){
                sa[k][j]=se[i];
                i++;
            }
         }
    }


    bz[1][1]=true;
    dfs(1,1);


    fclose(stdin);
    fclose(stdout);
    return 0;
}
