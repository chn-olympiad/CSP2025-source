#include<bits/stdc++.h>
using namespace std;
int r[15][15];
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int y=a[1],max,ma;
    for(int i=1;i<=n*m;i++){
        max=0;
        ma=0;
        for(int j=i;j<=n*m;j++){
            if(a[j]>max){
                max=a[j];
                ma=j;
            }
        }
        if(ma!=i){
            int=a[i];
            a[i]=a[ma];
            a[ma]=t;
        }
    }
    int c=1;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                r[i][j]=a[c];
                c++;
            }
        }
        else{
            for(int j=m;j>=1;j--){
                r[i][j]=a[c];
                c++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(r[i][j]==y){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
