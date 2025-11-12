#include <bits/stdc++.h>
using namespace std;
int n,m;
int c[505],maxn=-1e8,cnt=0;
long long ans;
const int mod=998244353;
string s;
bool flag=1;
void solve(){
    long long ans=1;
    for(int i=1;i<=n-cnt+1;i++){
        ans=ans*i%mod;
    }
    cout<<ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        maxn=max(maxn,c[i]);
        if(c[i]==0) cnt++;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==0) flag=0;
    }
    if(flag==1) solve();
return 0;
}
