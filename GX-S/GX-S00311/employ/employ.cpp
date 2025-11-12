#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1001,mod=998244353;

ll f[N];
void init(int x){
    f[0]=1;
    for(ll i=1;i<=x;i++){
        f[i]=i*f[i-1]%mod;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    init(n);
    cout<<f[m]%mod;
    return 0;
}
