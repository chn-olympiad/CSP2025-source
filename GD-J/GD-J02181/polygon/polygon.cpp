#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    int n,a[5001],sum[5002],num=0;
    sum[0]=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=3;j<=n;j++){
            if (sum[j]-sum[i-1]>sum[j]*2){
                num++;
                num%=998244353;
            }
        }
    }
    cout<<num<<endl;
    return 0;
}
