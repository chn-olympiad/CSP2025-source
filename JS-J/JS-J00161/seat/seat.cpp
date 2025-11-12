#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],s,sc[110];
bool cmp(int a1,int b1){
    return a1>b1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sc[i];
    }
    s=sc[1];
    sort(sc+1,sc+1+n*m,cmp);
    int x=1,y=1;
    for(int i=1;i<=n*m;i++){
        a[x][y]=sc[i];
        if(y%2==1&&x==n){
            y++;
            continue;
        }
        if(y%2==0&&x==1){
            y++;
            continue;
        }
        if(y%2==1){
            x++;
        }
        else x--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s==a[i][j]){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
}
