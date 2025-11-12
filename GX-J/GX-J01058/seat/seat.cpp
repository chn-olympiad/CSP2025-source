#include<bits/stdc++.h>
using namespace std;
int n,m,s[110][110],z[110][110],cmp[110][110],ans,x=1,a=0,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    x=m*n;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            ans=s[1][1];

    }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cmp[1][x]=s[i][j];


        }
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           z[i][j]=cmp[1][y];
    }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(ans==z[i][j]){
            cout<<i<<" "<<j;
          }


        }
    }

    return 0;
}
