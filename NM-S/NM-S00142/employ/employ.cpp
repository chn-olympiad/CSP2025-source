#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[505],c[505],s[505];
const ll p=998244353;
ll ppow(ll n){
    if(n==0)return 0;
    ll ans=1;
    for(ll i=2;i<=n;i++){
        ans*=i;
        ans%=p;
    }
    return ans;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll n,m;
    bool pd=true;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%1lld",&a[i]);
        s[i]==s[i-1]+abs(1-a[i]);
        if(a[i]==0)pd=false;
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    if(pd){
        printf("%lld",ppow(n)%p);
        return 0;
    }
    if(m==n){
        sort(c+1,c+n+1,cmp);
        int sum=0;
        for(int i=1;i<=n;i++){
            if(c[i]<s[n-i+1]){
                sum++;
            }
            else break;
        }
        printf("%lld",ppow(sum)%p);
        return 0;
    }
    return 0;
}
