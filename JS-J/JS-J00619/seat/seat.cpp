#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int g[110],d=0,c=1,r=1,k=101;
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>g[i];
    }
    for(int i=1; i<=n*m; i++){
        if(i>1){
            k=d;
        }
        d=0;
        for(int j=1; j<=n*m; j++){
            if(g[j]>d&&g[j]<k){
                d=g[j];
            }
        }
        if(c<=m&&r<=n&&c%2!=0&&c>0&&r>0){
            a[r][c]=d;
            r++;
        }
        else{
            if(c==m,r==n){
                a[r][c]=d;
                break;
            }
            if(c<=m&&r<=n&&c%2==0){
            a[r][c]=d;
            r--;
            }
            if(c>m){
                c--;
                break;
            }
            if(r>n){
                c++;
                r--;
                a[r][c]=d;
                r--;
            }
            if(r<=0){
                c++;
                r++;
                a[r][c]=d;
                r++;
            }
            if(c>m){
                c--;
                break;
            }
        }
    }
    for(int i=1; i<=n*m; i++){
        for(int j=1; j<=n*m; j++){
            if(a[i][j]==g[1]){
                cout<<j<<" "<<i<<endl;
            }
        }
    }
    return 0;
}
