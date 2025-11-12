
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1000;
const int mod=998244353;
int n,m;
int a[N],b[N];
int jc[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=m;j++){
        cin>>b[j];
    }
    jc[0]=1;
    for(int i=1;i<=500;i++){
        jc[i-1]%=mod;
        i%=mod;
        jc[i]=jc[i-1]*i%mod;
    }
    cout<<jc[n]%mod;
    return 0;
}
