#include <bits/stdc++.h>
using namespace std;
const int N=5e5+110;
long long n,k,a[N],ans,book[N],sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            book[i]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(book[i]==1)continue;
        sum=a[i];
        for(int j=i+1;j<=n;j++){
            if(book[j]==1)break;
            sum^=a[j];
            if(sum==k){
                ans++;
                book[i]=book[j]=1;
                break;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
