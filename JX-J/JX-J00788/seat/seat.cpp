#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R;
int f[15][15],xian=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                f[j][i]=a[xian++];
            }
        }
        else{
            for(int j=1;j<=m;j++){
                f[j][i]=a[xian++];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(R==f[i][j]){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
