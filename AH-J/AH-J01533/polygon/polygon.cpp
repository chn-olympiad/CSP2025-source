#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const int N=5e3+5;
const int mod=998244353;
ll sum, tan[N];
int n, a[N];
int maxn=-1;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n; tan[0]=1; tan[1]=1;
    for(int i=2; i<=n; i++) {
        tan[i]=tan[i-1]*i;
        tan[i]%=mod;
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]); sum+=a[i];
        maxn=max(maxn, a[i]);
    }
    if(n==3) {
        if(sum>maxn*2) cout<<1;
        else cout<<0;
        return 0;
    } else if(maxn==1) {
        ll ans=0;
        for(int i=3; i<=n; i++) {
            ll tmp=tan[n]/(tan[i]*tan[n-i]);
            ans%=mod;
            ans+=tmp; ans%=mod;
        }
        cout<<ans; return 0;
    }
    return 0;
}

