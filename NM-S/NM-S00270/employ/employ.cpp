#include<bits/stdc++.h>
using namespace std;
int n,m,s[510],c[510];
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        ans=(ans*i+998244353)%998244353;
    }
    cout<<(ans+998244353)%998244353;
    return 0;
}

