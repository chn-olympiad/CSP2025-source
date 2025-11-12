#include <bits/stdc++.h>
using namespace std;
long long a[5001];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n-2;i++){
        for(long long j=i+1;j<=n-1;j++){
            for(long long k=j+1;k<=n;k++){
                if(a[i]+a[j]+a[k]>2*a[k]) ans++;
                else break;
            }
        }
    }
    printf("%lld",ans);
}
