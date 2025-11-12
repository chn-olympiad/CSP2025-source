#include<bits/stdc++.h>
using namespace std;
long long a[123][123];9
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int r=a[1][1];
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            if(i==1){
                if(a[i][j]<a[i][j+1]){
                    swap(a[i][j],a[i][j+1]);
                }
            }
            if(j==n){

                if(a[i][j]<a[i+1][j]){
                    swap(a[i][j],a[i][j+1]);
                }
            }
        }
    }
    return 0;
}
