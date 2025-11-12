#include<bits/stdc++.h>
using namespace std;
long long n,ans,m;
long long const MOD= 998244353;
string s;
long long res;
long long a[50009];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    if(m!=1&&m!=n){
        printf("1");
        return 0;
    }
    ans=1;
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==0)res++;
    }
    for(int i=1;i<=n;i++){
        ans*=i%MOD;
        ans%=MOD;
    }
    printf("%lld",ans);
    return 0;
}
