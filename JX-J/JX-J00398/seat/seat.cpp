#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",std.in);
    freopen("seat.out","w",std.out);
    int n,m;
    cin>>n>>m;
    int c=n*m;
    int a[n+1][m+1];
    int b[110],w[110],s=0,x,y;
    for(int i=1;i<=c;i++){
        cin>>b[i];
    }
    s=b[1];
    sort(b+1,b+c+1);
    for(int i=1;i<=c;i++){
        w[c-i+1]=b[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==1){
                a[j][i]=w[(i-1)*n+j];
            }else if(i%2==0){
                a[j][i]=w[i*n-j+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == s){
                x=i;
                y=j;
            }
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
