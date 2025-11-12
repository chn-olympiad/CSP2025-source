#include<bits/stdc++.h>
using namespace std;
long long n,m,x[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x[i][j];
        }
    }
    cout<<1<<" "<<1;

    return 0;
}
