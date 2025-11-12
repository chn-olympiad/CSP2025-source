#include<bits/stdc++.h>
using namespace std;
int s[105];
int g[11][11];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x = 0,y = 1,num = 0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    num = s[1];
    sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(y%2==1){
            if(x==n){
                y++;
            }
            else{
                x++;
            }
        }
        else{
            if(x==1){
                y++;
            }
            else{
                x--;
            }
        }
        g[x][y] = s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==num){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
