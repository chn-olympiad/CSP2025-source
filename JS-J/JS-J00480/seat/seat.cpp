#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],g[11][11],t,x=1,y=1;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout); 
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        g[x][y]=a[i];
        if(x%2==1){
            if(y==n) x++;
            else y++;
        }
        else{
            if(y==1) x++;
            else y--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==t){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}