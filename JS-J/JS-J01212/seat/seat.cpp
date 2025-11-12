#include<bits/stdc++.h>
using namespace std;
int n,m,k,id,a[105],ans[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    k=a[1];
    int t=1;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++) {
        if(t){
            for(int j=1;j<=n;j++) {
                id++;
                ans[j][i]=a[id];

            }
            t=!t;
        }
        else {
            for(int j=n;j>=1;j--) {
                id++;
                ans[j][i]=a[id];
            }
            t=!t;
        }
    }
   /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(k==ans[i][j]){
                cout<<j<<' '<<i;
                break;
            }
        }
    }
    return 0;
}
