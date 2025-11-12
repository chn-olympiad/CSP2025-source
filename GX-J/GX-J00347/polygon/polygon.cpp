#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[10001],b[10001],t=1,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        t*=i;
    }
    for(int i=3;i<=n;i++){
            int sum=1,sum1=1;
        for(int j=2;j<=i;j++){
            sum*=j;
        }
        for(int j=2;j<=n-i;j++){
            sum1*=j;
        }
        ans+=t/(sum*sum1);
        ans%=M;
    }
    cout<<ans;
    return 0;
}
