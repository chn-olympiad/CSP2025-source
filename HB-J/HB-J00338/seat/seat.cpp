#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=n*m,y;
    int b[10005]={};
    int c[10005]={};
    int a[105][105]={},d[105][105]={};
    for(int i=1;i<=x;i++){
        cin>>b[i];
        if(i==1) y=b[i];
    }
    sort(b+1,b+1+x);
    for(int i=x;i>=1;i--){
        c[i]=b[i];
    }
    int f=1;
    for(int l=1;l<=m;l++){
        if(l%2==1){
            for(int h=1;h<=n;h++){
                a[h][l]=c[f];
                f++;
            }
        }else{
            for(int h=n;h>=1;h--){
                a[h][l]=c[f];
                f++;
            }
        }
    }
    int v=1,t=1;
    for(int j=m;j>=1;j--){
        if(j%2==1){
            v=1;
            for(int i=n;i>=1;i--){
                d[v][t]=a[i][j];
                v++;
            }
        }else{
            v=n;
            for(int i=1;i<=n;i++){
                d[v][t]=a[i][j];
                v--;
            }
        }
        t++;
    }
    int p=0,q=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(d[i][j]==y){
                p=i;
                q=j;
            }
        }
    }
    cout<<q<<' '<<p;
    return 0;
}
