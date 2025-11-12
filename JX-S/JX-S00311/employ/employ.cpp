#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m;
ll ans;
const int maxn=505;
bool a[maxn];
int c[maxn],dp[1<<20],cou[1<<20];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(m==n){
    printf("0");return 0;}
    ans=1;
    while(n>0){
        ans=ans*n;
        ans%=mod;
        n--;
    }
    printf("%lld\n",ans);
    return 0;
}
