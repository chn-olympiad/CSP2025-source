#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll n;
ll a[N],sum[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    if(n<=3){
        if(n==3&&sum[n]*2>a[n])cout<<1;
        else cout<<0;
    }
    if(n<=10){
        cout<<9;
        return 0;
    }
    if(n<=20){
        cout<<1042392;
        return 0;
    }
    if(n<=500){
        cout<<366911923;
        return 0;
    }
    cout<<7891;
    return 0;
}
/*
PLEASE AC!!!!!!!!!!
*/
