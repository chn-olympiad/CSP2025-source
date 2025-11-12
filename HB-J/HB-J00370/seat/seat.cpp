#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[105],c[105][105];
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
    int sum=a[1],cnt=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=m;j++){
                c[i][j]=a[++cnt];
            }
        }else{
            for(int j=m;j;j--){
                c[i][j]=a[++cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(sum==c[i][j]){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }

    return 0;
}
