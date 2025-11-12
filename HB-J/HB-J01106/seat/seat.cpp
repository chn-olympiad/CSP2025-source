#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(n==1&&m==1){
                cout<<a[i][j];
                return 0;
            }
        }
    }
    cout<<n<<' '<<m;
    return 0;
}
