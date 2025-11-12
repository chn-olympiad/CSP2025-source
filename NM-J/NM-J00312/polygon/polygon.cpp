#include<bits/stdc++.h>
using namespace std;
const int N=5000,M=998244353;
typedef long long LL;
LL q[N],ans;
int n,big,arr[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n,q[1]=1;
    for(int i=0;i<n;i++)cin>>arr[i],big=max(big,arr[i]);
    for(int i=2;i<N;i++)q[i]=q[i-1]*i%M;
    if(big==1){
        for(int i=3;i<n;i++)ans=(ans+q[n]/q[n-i]/q[i])%M;
        cout<<ans;
        return 0;
    }
    for(LL i=0;i<1<<n;i++){
            int a=0,m=0;
        for(int j=0;j<n;j++)if(i>>j&1)m=max(m,arr[j]),a+=arr[j];
        if(a>m*2)ans++;
    }
    cout<<ans;
}
