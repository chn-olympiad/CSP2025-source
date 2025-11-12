#include<bits/stdc++.h>
using namespace std;

int n,a[5005];int sum[5005][5005];int mod=998244353;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(j==1)sum[i][j]=a[i];
            else sum[i][j]=sum[i][1]-sum[j][1];
            //cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
        }
    }
    long long ans=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=i;j++){
                if(sum[i][j]>a[k]){
                    ans++;
                    cout<<sum[i][j]<<" "<<a[k]<<" "<<k<<endl;
                }
                cout<<sum[i][j]<<" "<<a[k]<<" "<<k<<endl;
            }
        }
    }
    cout<<ans%mod;
}
