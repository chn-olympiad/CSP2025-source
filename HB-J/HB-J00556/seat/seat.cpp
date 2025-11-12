#include <bits/stdc++.h>
using namespace std;
int a[105];
int seat[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b=1;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin >> a[i];
    int j1=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                seat[j][i]=a[b++];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                seat[j][i]=a[b++];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seat[i][j]==j1) cout << j << ' ' << i;
        }
    }
    return 0;
}
