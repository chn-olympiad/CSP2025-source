#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            cnt++;
            continue;
        }
        long long sum=0;
        for(int j=i;j<=n;j++){
            sum^=a[j];
            if(a[j+1]==k&&sum!=k)
                break;
            if(sum==k||a[j]==k){
                cnt++;
                i=j;
                break;
            }
        }
    }
    printf("%lld",cnt);
    return 0;
}
