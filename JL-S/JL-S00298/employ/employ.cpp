#include<bits/stdc++.h>
using namespace std;
map<long long, long long>mp;
#define MOD 998244353
int main(){
//    freopen("employ.in", "r", stdin);
//    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, m, maxn=0; char c[505];
    cin>>n>>m>>c;
    for(long long i=1; i<=n; i++){
        long long x;
        cin>>x;
        maxn=max(maxn, x);
        mp[x]++;
    }
    long long sum=1;
    for(long long i=1; i<=maxn; i++){
        sum=(((sum%MOD)*((mp[i]+1)%MOD))-(sum%MOD))%MOD;
    }
    cout<<sum;
    return 0;
}
