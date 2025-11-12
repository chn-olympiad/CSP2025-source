#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],x,y,d,yyy,cnt;
bool cmp(int t,int z){
    return t>z;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];
    yyy=a[1];
    sort(a+1,a+1+n*m,cmp);
    x=1,y=1,d=0,cnt=1;
    while(x<=n&&y<=m){
        b[x][y]=a[cnt];
        if(d==0){
            for(int i=1;i<n;++i){
                x++,cnt++,b[x][y]=a[cnt];
            }
            d=1,++y,++cnt;
        }
        else{
            for(int i=1;i<n;++i){
                --x,++cnt,b[x][y]=a[cnt];
            }
            d=0,++y,++cnt;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(b[i][j]==yyy){
                cout<<j<<' '<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
