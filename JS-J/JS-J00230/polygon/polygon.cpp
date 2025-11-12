#include <bits/stdc++.h>
#define ll long long
#define str string
#define N 5003
#define MOD 998244353
using namespace std;

bool st;
int a[N];
ll f[N],ff;
bool ed;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    fprintf(stderr,"%lf\n",(&ed-&st)/1024.0/1024);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    f[0]=1;
    ll r=0;
    for(int i=1;i<=n;i++){
        ll s=ff;
        for(int j=a[i]+1;j<N;j++) (s+=f[j])%=MOD;
        (r+=s)%=MOD;
        (ff*=2)%=MOD; for(int j=N-1;j>=0;j--){
            if(j+a[i]>=N) (ff+=f[j])%=MOD;
            else (f[j+a[i]]+=f[j])%=MOD;
        }
    }
    printf("%lld\n",r);
    return 0;
}
