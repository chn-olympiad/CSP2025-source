#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;



signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int s[n+5];
    for(int i =0;i<n;i++){
        cin>>s[i];
    }
    int c[n+5];
    for(int i = 0;i<n;i++){
        cin>>c[i];
    }
    int ans =1;
    for(int i =1;i<=n;i++){
        ans = ans % 998244353;
        ans = ans*i;
        ans  = ans% 998244353;
    }
    cout<<ans;
    return 0;
}
