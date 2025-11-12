#include<bits/stdc++.h>
using namespace std;
int a[205];
int b[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j%2){
                b[i][j]=(j-1)*n+i;
            }
            else{
                b[i][j]=j*n-i+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[b[i][j]]==t){
                cout<<j<<" "<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
