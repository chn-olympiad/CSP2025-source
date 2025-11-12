#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,a[100010],f[110][110],k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ll xo=0;
        for(int j=i;j<=n;j++){
            xo^=a[j];
            if(xo==k)f[i][j]=1;
        }
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            for(int j=i;j<=i+l-1;j++)f[i][i+l-1]=max(f[i][i+l-1],f[i][j]+f[j+1][i+l-1]);
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++)cout<<f[j][j+i-1]<<' ';
        cout<<endl;
    }
    */
    cout<<f[1][n];
    return 0;
}
