#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1005];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int u=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    int x[1005][1005];
    int z=1;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                x[j][i]=a[z];
                z++;
            }
        }
        else{
            for(int j=m;j>=1;j--){
                x[j][i]=a[z];
                z++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i][j]==u){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
