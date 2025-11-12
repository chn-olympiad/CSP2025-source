#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int b[101][101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int t=n*m;
    int a[10001];
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    int g=a[1];
    sort(a+1,a+1+t,cmp);
    int ii=1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                b[i][j]=a[ii];
                ii++;
            }
        }
        else{
            for(int j=m;j>=1;j--){
                b[i][j]=a[ii];
                ii++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==g){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
