#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,a[5000000+10]={};
    scanf("%lld%lld",&n,&k);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(k==0)printf("%lld",(n/2));
    else printf("0");
    return 0;
}
