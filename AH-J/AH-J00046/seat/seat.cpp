#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],t[15][15];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    long long k=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j%2==1){
                t[i][j]=a[n*(j-1)+i];
            }else{
                t[i][j]=a[n*(j-1)+n-i+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i][j]==k){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
