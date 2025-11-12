#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int b[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,xm;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    xm=a[1];
    int k=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                b[j][i]=a[++k];
            }
        }
        else{
             for(int j=m;j>=1;j--){
                b[j][i]=a[++k];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==xm){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
