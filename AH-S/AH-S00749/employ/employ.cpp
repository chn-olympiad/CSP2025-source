#include <bits/stdc++.h>
using namespace std;
int n,m;
long long s[505],c[505],ans=1;
long long mod=998244353;
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>s[i];
    }
    for (int i=1; i<=n; i++){
        cin>>c[i];
    }
    if (n==m) {
        cout <<0;
        return 0;
    }
    if (m==1) {
        for (int i=1; i<n; i++){
            ans=(ans*i)%mod;
            cout <<ans;
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    cout <<ans;
    return 0;
}
