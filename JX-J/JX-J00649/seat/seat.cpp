#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[101]={},b[11][11]={},f;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    f=a[1];
    for(long long i=1;i<=n*m;i++){
        for(long long j=1;j<m*n;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    long long o=1;
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            b[j][i]=a[o];
            o++;
        }
        i++;
        for(long long j=n;j>=1;j--){
            b[j][i]=a[o];
            o++;
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(b[i][j]==f){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
