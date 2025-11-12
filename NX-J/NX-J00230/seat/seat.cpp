#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m-1];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[0];
    int f=0,g=0;
    int k[n][m];
    int h=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(h>=n){

            }
            k[i][j]=a[h];
            h++;
        }
    }
    cout<<n<<m;
    return 0;
}
