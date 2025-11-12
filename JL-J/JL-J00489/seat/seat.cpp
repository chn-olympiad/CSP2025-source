#include<bits/stdc++.h>
using namespace std;
int n,m,b[10000],a[15][15];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int j=0;j<m*n;j++){
        cin>>b[j];
    }
    int z=b[1];
    sort(b,b+(m*n),cmp);
    int t=0,i=1;
        for(int j=1;j<=m;j++){
            if(j%2!=0){
                a[i][j]=b[t];
                i++;
                t++;
            }
            else{
                a[i][j]=b[t+n-i+1];
                i--;
                t+=n;
            }
        }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(a[i][j]==z)cout<<i<<' '<<j;
        }
    }
        return 0;
}
