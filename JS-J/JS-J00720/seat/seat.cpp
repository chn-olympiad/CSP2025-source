#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,cj[1005],x=0,zw[105][105];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>cj[x++];
        }
    }
    r=cj[0];
    sort(cj,cj+x-1,f);
    x=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            zw[j][i]=cj[x++];
        }
        i++;
        if(i>m)break;
        for(int j=n;j>=1;j--){
            zw[j][i]=cj[x++];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(zw[i][j]==r){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
