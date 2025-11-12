#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int b[101];
int g,k=1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>b[i];
    g=b[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(b[i]<=b[j]) swap(b[i],b[j]);
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                a[i][j]=b[k];
                k++;
            }
        }
        else if(i%2==0){
            for(int j=n;j>=1;j--){
                a[i][j]=b[k];
                k++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==g){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
