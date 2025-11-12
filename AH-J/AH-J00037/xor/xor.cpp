#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,maxn=0,cnt=0;
LL a[1000000+10];
LL sum[1000000+10];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i]^a[i];
    }
    LL l=1;
    for(int r=1;r<=n;r++){
        for(int l=n;l>=r;l--){
            if((sum[l]^sum[r])==k){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
