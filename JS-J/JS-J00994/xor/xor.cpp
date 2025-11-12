#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],sum[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%ld%ld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%ld",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            if((sum[i]^sum[j-1])==k){
                cnt++;
                i=j;
                break;
            }
        }
    }
    printf("%ld",cnt);
    return 0;
}
