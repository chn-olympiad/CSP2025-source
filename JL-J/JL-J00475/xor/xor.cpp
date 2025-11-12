#include <cstdio>
using namespace std;
long long a[500005],f[500005],n,k;
int main(){
    scanf("%lld", &n);
    scanf("%lld", &k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=n;i++){
        if(a[i]==k){
            f[i]++;
        }
        if(a[i] xor a[i-1]==k){
            f[i]=f[i-1];
        }
    }
    printf("%lld", f[n]);
    return 0;
}
