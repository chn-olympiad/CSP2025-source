#include<bits/stdc++.h>
using namespace std;
const int N=5010,P=998244353;
int n,a[N],c[N];
long long ans,p[N],f[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    sort(a+1,a+n+1);
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[n];j>=a[i];j--){
            f[j]=(f[j]+f[j-a[i]])%P;
        }
    }
    for(int i=1;i<=a[n];i++){
        f[i]=(f[i]+P-c[i])%P;
    }
    f[0]=0;
    for(int i=1;i<=a[n];i++){
        f[i]=(f[i]+f[i-1])%P;
    }
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*2%P;
    }
    for(int i=3;i<=n;i++){
        ans=(ans+p[i-1]+P-i+P-f[a[i]])%P;
    }
    printf("%lld",ans);
    return 0;
}
