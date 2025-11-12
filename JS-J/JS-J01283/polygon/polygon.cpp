#include <bits/stdc++.h>
using namespace std;
long long n,l[5999];
long long f[5999][5999];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    long long as=0;
    for(int i=0;i<n;i++){
        cin>>l[i];
        as=max(as,l[i]);
    }

    sort(l,l+n);
    for(int j=0;j<=l[0];j++){
        f[0][j]=1;
    }
    f[0][0]=2;
    for(int i=1;i<n;i++){
        for(int j=0;j<=as+5;j++){
            if(j-l[i]>=0){
                f[i][j]=(f[i-1][j-l[i]]+f[i-1][j])%998244353;
            }
            else{
                f[i][j]=(f[i-1][0]+f[i-1][j])%998244353;
            }
        }
    }
    long long sum=0;
    for(int i=1;i<n;i++){
        sum=(sum+f[i-1][l[i]+1])%998244353;
    }
    cout<<sum;
    return 0;
}
