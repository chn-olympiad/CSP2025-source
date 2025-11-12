//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
//I love CCF!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=2147483647;
const ll LLINF=9223372036854775807;
const ll N=5000+10;
ll n;
ll a[N];
ll pro[100]={
    //I love CCF!!!!!!!!!
    1,
    1,
2,
6,
24,
120,
720,
5040,
40320,
362880,
3628800,
39916800,
479001600,
6227020800,
87178291200,
1307674368000,
20922789888000,
355687428096000,
6402373705728000,
121645100408832000,
2432902008176640000,
};
ll exmax(ll a,ll b,ll c){
    if(a>b && a>c)return a;
    if(b>a && b>c)return b;
    if(c>a && c>b)return c;
    return 0;
}
ll func(ll n){
    ll ans=0;
    for(ll i=1;i<=n-3;i++){
        ans+=pro[n-3]/pro[n-3-i]/pro[i];
    }
    return ans;
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
    cin >> n;

    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll tmp=func(n);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            for(ll k=j+1;k<=n;k++){
                if(exmax(a[i],a[j],a[k])*2<a[i]+a[j]+a[k]){
                    cnt+=tmp;
                }
            }
        }
    }
    cout << cnt<<endl;
}
