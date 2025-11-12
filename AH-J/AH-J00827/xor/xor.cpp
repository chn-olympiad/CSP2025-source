#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5;
LL a[N],sum[N];
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    LL n,k;
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(LL i=1;i<=n;i++){

    }
    return 0;
}
