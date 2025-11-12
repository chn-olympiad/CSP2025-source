#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,b[15][15],c;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            r=a[i];
        }
    }
    sort(a,a+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                b[i][j]=a[c];
                c++;
            }
        }else{
            for(int j=n;j>=1;j--){
                b[i][j]=a[c];
                c++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==r){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
