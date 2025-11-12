#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++){
        long long sum=0;
        for(long long j=i;j<=n;j++){
            sum=sum xor a[j];
            if(sum==k){
                cnt++,i=j;
                break;
            }
        }
    }
    printf("%lld",cnt);
    return 0;
}
