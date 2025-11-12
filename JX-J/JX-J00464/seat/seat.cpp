#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[11][11],b[105],c[105],i,j,k,t,n,m;
    cin>>n>>m;
    for(i=0;i<n*m;i++){
        cin>>b[i];
    }
    k=b[0];
    sort(b,b+n*m);
    for(i=0;i<n*m;i++){
        c[i]=b[n*m-i-1];
    }
    t=0;
    for(j=1;j<=m;j++){
        if(j%2==1){
            for(i=1;i<=n;i++){
                a[i][j]=c[t];
                t++;
            }
        }else{
        for(i=n;i>=1;i--){
                a[i][j]=c[t];
                t++;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==k){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
