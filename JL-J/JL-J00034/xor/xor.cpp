#include<bits/stdc++.h>
using namespace std;
unsigned long n,k;long long a[500005],ans;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
scanf("%lld%lld%lld",&n,&k,&a[1]);

k=min(k,n);
for(int i=2;i<=n;i++){scanf("%lld",&a[i]);}
for(int i=1;i<=n;i++){
        long long sum=a[i];
        if(sum==k)ans++;
    for(int j=i+1;j<=n;j++){
        sum^=a[j];
        if(sum==k)ans++;
    }

}
printf("%lld",ans);
return 0;

}
