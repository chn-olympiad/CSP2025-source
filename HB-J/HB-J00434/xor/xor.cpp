#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[5000005];
long long b[5000005];
long long ans=0;
long long bj=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]^b[i-1];
    }
    for(long long i=1;i<=n;i++){
        i=bj+1;
        for(long long j=i;j<=n;j++){
            long long cnt=0;
            for(long long k=i;k<=j;k++){
                cnt^=a[k];
            }
            if(cnt==k){
               // cout<<i<<' '<<j<<endl;
                bj=j;
                ans++;
                break;
            }

        }
    }
    cout<<ans;
    return 0;
}
