#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],sum[N];
int f[5000005],g[5000005];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    f[0]=1;
    for(int i=1;i<n;i++){
        for(int j=sum[i];j>=a[i];j--){
            f[j]=((long long)f[j]+f[j-a[i]])%mod;
            g[j]=f[j-a[i]];
        }
        int k=i;
        for(int j=a[i];j<=sum[i];j++){
            while(k<n&&a[k+1]<j){
                k++;
            }
            ans+=((long long)k-i)*g[j];
            ans%=mod;
        }
    }
    cout<<ans;
    return 0;
}
