#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
bool A=1;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    int ans=1;
    for(int i=1;i<=n;i++) ans=(1ll*ans*i%998244353+998244353)%998244353;
    cout<<ans;
    return 0;
}