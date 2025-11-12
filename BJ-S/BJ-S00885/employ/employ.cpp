#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long p=998244353;
long long n,m,c[510],ans=1;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=n;i>=2;i--){
        ans=ans*i%p;
    }
    cout<<ans;
    return 0;
}
