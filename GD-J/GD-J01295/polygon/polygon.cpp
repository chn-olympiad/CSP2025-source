#include<bits/stdc++.h>
#define mod 998244353
#define N 5003
#define V 7000
using namespace std;
int n;
int a[N];
long long f[V];
long long res;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i]+1;j<=6000;j++){
            res=(res+f[j])%mod;
        }
        for(int j=6000;j>=0;j--){
            f[min(6000,j+a[i])]=(f[min(6000,j+a[i])]+f[j])%mod;
        }
    }
    printf("%lld\n",res);
}