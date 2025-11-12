#include<bits/stdc++.h>
using namespace std;
bool qw(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    int a[101][101]={0},b[101]={0},q,w,s=0;
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
        cin>>w;
        b[i]=w;
        if(i==1){
            q=w;
        }
    }
    sort(b+1,b+n*m+1,qw);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
                a[i][j]=b[i*j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==q){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
