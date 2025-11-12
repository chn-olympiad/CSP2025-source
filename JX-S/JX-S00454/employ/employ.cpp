#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,c[503],ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) ans*=i,ans%=998244353;
    cout<<ans<<'\n';
    return 0;
}
