#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],q,mp[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    q=a[1];
    sort(a+1,a+1+n*m,cmp);
    int ii=1,j=1;
    for(int i=1;i<=m;i++){
        if(j<=1){
            for(j=1;j<=n;j++){
                mp[j][i]=a[ii];
                ii++;
            }
        }else{
            for(j=n;j>=1;j--){
                mp[j][i]=a[ii];
                ii++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mp[i][j]==q){
                cout<<j<<' '<<i;
            }
        }
    }
    return 0;
}
