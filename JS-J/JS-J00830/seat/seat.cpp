#include<bits/stdc++.h>
using namespace std;
int mark[105],seat[11][11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int mr;
    cin>>mr;
    mark[1]=mr;
    for(int i=2;i<=n*m;i++){
        cin>>mark[i];
    }
    sort(mark+1,mark+1+n*m,greater<int>());
    int t=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                seat[j][i]=mark[t];
                t++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                seat[j][i]=mark[t];
                t++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seat[i][j]==mr){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
