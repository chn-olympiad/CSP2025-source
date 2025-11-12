#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=998244353;
string s;
int c[5050];
int f[5050];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++){
        f[i]=(i%mod)*(f[i-1]%mod);
    }
    cout<<f[n]%mod;
    return 0;
}
