#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long n,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3])  printf("1");
        else    printf("0");
    }
    else{
        if(a[n]==1){
            if((n-1)%2==0)  printf("%lld",(n-1)/2*(n-2)%998244353);
            else    printf("%lld",(n-2)/2*(n-1)%998244353);
        }
    }
    return 0;
}
