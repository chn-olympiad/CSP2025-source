#include <bits/stdc++.h>
using namespace std;
int mx=0,f[100][4]={0},a1=0,a2=0,a3=0;
int qx[]={1,1,1,1,1};
int qy[]={-2,-1,0,1,2};
void dfs(int x,int y,int sum,int n){
    if(x==n){
        if(a1<=(n/2) && a2<=(n/2) && a3<=(n/2)){
            if(sum>mx){
                mx=sum;
                }
        }
        a1=0;
        a2=0;
        a3=0;
        return;
    }
    for(int i=0;i<5;i++){
        int tx=x+qx[i];
        int ty=y+qy[i];
        if(ty>=0 && ty<=3 && tx>=1 && tx<=n){
            if(a1<=(n/2) && a2<=(n/2) && a3<=n/2){
                if(ty==0){a1++;}
                if(ty==1){a2++;}
                if(ty==2){a3++;}
                dfs(tx,ty,sum+f[tx][ty],n);
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;

    cin>>t;
    for(int l=0;l<t;l++){
    int n;
    mx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i][0];
        cin>>f[i][1];
        cin>>f[i][2];
    }
    a1=0;
    a2=0;
    a3=0;
    for(int i=0;i<=2;i++){
        dfs(1,i,f[1][i],n);
    }

    cout<<mx<<endl;
}
    return 0;
}
