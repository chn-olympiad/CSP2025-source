#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],g[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) t=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(t==a[i]){
            t=i;
            break;
        }
    }
    int lr=1;
    for(int j=1;j<=m;j++){
        if(j%2){
            for(int i=1;i<=n;i++){
                g[i][j]=lr;
                lr++;
            }
        }else{
            for(int i=n;i>=1;i--){
                g[i][j]=lr;
                lr++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==t){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
