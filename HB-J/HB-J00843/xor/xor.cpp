#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,ans;
long long a[N],sum[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        long long qd=i;
        for(long long j=i;j<=n;j++){
            if((sum[j]^sum[qd-1])==k){
//                cout<<sum[j]<<" "<<sum[qd-1]<<" "<<(sum[j]^sum[qd-1])<<endl;
//                cout<<i<<" "<<j<<" "<<qd<<"\n";
                cnt++;
                qd=j+1;
            }
        }
//      cout<<cnt<<endl;
        ans=max(ans,cnt);
        cnt=0;
    }
    cout<<ans;
    return 0;
}
