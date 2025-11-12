#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[600000],sum[600000];
long long l=INT_MAX,r=INT_MIN;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]^sum[i-1];
        cout<<i<<' '<<sum[i]<<endl;
  }
    cout<<endl;
    for(long long i=1;i<=n;i++){
    for(long long j=i;j<=n;j++){
        if(((sum[i-1]^sum[j])==k || i==j  and a[i]==k )and ( j<l or i>r)){
        ans++;
        l=min(l,i);
        r=max(r,j);
        cout<<i<<' '<<j<<endl;
        }
    }
  }
  cout<<ans;
  return 0;
}
