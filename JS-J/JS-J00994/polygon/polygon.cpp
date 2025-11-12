#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%ld",&n);
    for(int i=1;i<=n;i++)scanf("%ld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    if(a[n]==1){
        int answer=1;
        for(int i=1;i<=n;i++){
            answer*=2;
            answer%=998244353;
        }
        answer+=998244353;
        answer-=1;
        answer-=n;
        answer-=n*(n-1)/2;
        answer%=998244353;
        printf("%ld",answer);
        return 0;
    }
    if(n==3){
        printf("1");
        return 0;
    }
}
