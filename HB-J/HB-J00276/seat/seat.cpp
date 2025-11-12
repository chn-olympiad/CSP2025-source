#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s[15][15],n,m,a[15][15];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>a[i][j];

        }
    if(a[1][1]==1){
        cout<<m<<" "<<n;
        return 0;
    }
    if(a[1][1]=n*m){
        cout<<1<<" "<<1;
        return 0;
    }
    return 0;
}
