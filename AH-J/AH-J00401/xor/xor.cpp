#include<bits/stdc++.h>
using namespace std;
long long n,k,a[2000010],sum[2000010],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    long long l=1,r=1;
    while(r<=n){
        long long s=sum[r]^sum[l-1];
        if(s==k){
            ans++;
            l=r+1;
        }
        r++;
    }
    cout<<ans;
    return 0;
}
