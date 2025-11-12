#include<bits/stdc++.h>
using namespace std;
int b[10005],a[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ren,p=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        ren=b[1];
    }
    for(int i=1;i<=n*m-1;i++){
        for(int j=1;j<=n*m-1;j++){
            if(b[j]<b[j+1])swap(b[j],b[j+1]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[j][i]=b[p];
            p++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ren==a[j][i]&&i%2!=0){
                cout<<i<<' '<<j;
                return 0;
            }
            else {
                cout<<i<<' '<<n-j;
                return 0;
            }
        }
    }
    return 0;
}
