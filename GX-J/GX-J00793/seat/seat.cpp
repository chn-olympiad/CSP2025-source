#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],f[1001][1001],t;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long l=n*m;
    for(long long i=0;i<l;i++){
        cin>>a[i];
    }
    long long y=a[0];
    sort(a,a+l,cmp);
    for(long long i=1;i<=m;i++){
        if(i%2==1){
            for(int long long j=1;j<=n;j++){
                f[i][j]=a[t];
                t++;
            }
        }else if(i%2==0){
            for(int long long j=n;j>=1;j--){
                f[i][j]=a[t];
                t++;
            }
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            if(f[i][j]==y){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
