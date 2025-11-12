#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k,t;ll ans;
ll a[N];
ll sum[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            t=0;
        }
        else{
            t++;
            sum[t]=a[i]^sum[t-1];
            for(int j=0;j<t;j++){
                if((sum[j]^sum[t])==k){
                    ans++;
                    t=0;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
