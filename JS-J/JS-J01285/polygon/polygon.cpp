#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5005;
const long long mod=998244353;
int n,a[N];
long long f[N],g[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    memset(f,-0x3f,sizeof(f));
    f[0]=f[1]=f[2]=0;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i-2;j++)
            if(g[j]>a[i]*2 && f[j]+1>f[i]){
                f[i]=f[j]+1;
                g[i]=g[j]+a[i];
            }
    }
    printf("%lld",f[n]%mod);
    return 0;
}
