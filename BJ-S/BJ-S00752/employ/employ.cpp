#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,c[505];
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(auto&i:s) sum+=i-'0';
    if(m==n){
        if(sum!=n) return cout << 0, 0;
        if(sum==n){
            int ans=1;
            for(int i=1;i<=n;i++) if(c[i]==0) return cout << 0, 0;
            for(int i=1;i<=n;i++) ans=ans*i%998244353;
            cout << ans;
        }
    }
    return 0;
}
