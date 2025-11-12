#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,z,x=1,y=1,f;
    cin>>n>>m;
    long long a[n*m],b[n*m],c[n][m];
    for(long long i=0;i<=n*m-1;i++) cin>>a[i];
    f=a[0];
    for(long long i=0;i<=n*m-1;i++){
            b[i]=0;
        for(long long j=0;j<=n*m-1;j++){
            if(a[j]>b[i]){
                b[i]=a[j];
                z=j;
            }
        }
        for(long long k=0;k<=n*m-1;k++) if(k==z) a[k]=0;
    }
    for(long long i=0;i<=n*m-1;i++){
        c[x-1][y-1]=b[i];
        if(x==1&&y%2==0) y++;
        else if(x==n&&y%2!=0) y++;
        else if(y%2==0) x--;
        else if(y%2!=0) x++;
    }
    for(long long i=0;i<=n-1;i++){
        for(long long j=0;j<=m-1;j++){
            if(c[i][j]==f) cout<<j+1<<" "<<i+1;
        }
    }
    return 0;
}
