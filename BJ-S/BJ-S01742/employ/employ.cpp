#include <bits/stdc++.h>
#define int long long

using namespace std;

int mod=998244353;

signed main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

    int n,m;

    cin>>n>>m;

    string s;

    cin>>s;

    vector<int>c(n+1,0);

    for(int i=1;i<=n;i++) cin>>c[i];

    int ans=1;

    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=mod;
    }

    cout<<ans<<endl;
}
