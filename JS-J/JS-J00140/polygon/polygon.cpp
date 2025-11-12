#include <bits/stdc++.h>
using namespace std;
int q[505],f[500000][505];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        f[a[i]][i]=1;
    }
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    int cnt=0;
    for(int j=1;j<=n-1;j++){
        for(int x=0;x<=q[j];x++){
            int z=0;
            if(x-a[j]>=0){
                z=x-a[j];
            }
            else{
                z=0;
            }
            f[x][j]=f[z][j-1]+f[x][j-1]+f[x][j];
            if(x>a[j+1]&&j>=2){
                cnt+=f[x][j];
            }
            
        }
    }
    cout<<cnt%998244353<<endl;
}