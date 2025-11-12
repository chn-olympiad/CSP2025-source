#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
int dx[2]={1,-1};
int ss[20][20],n,m,l,ll,pp=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>ll;
        if(i==1){
            l=ll;
        }
        if(ll>l){
            pp++;
        }
    }
    memset(ss,-1,sizeof(ss));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ss[i][j]=0;
        }
    }
    int x=1,y=1,d=0,p=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ss[x][y]=p;
            p++;
            int nx=x+dx[d];
            if(ss[nx][y]==-1){
                y++;
                d=(d+1)%2;
            }else{
                x=nx;
            }
        }
    }

    int ax,ay;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ss[i][j]==pp)
                ax=j,ay=i;

        }
    }
    cout<<ax<<" "<<ay<<endl;
    return 0;
}
