#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
const long long mod=998244353;
string s;
bool flag=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=0;i<s.length();i++)if(s[i]==0)flag=0;
    if(flag){
        long long ans=1ll;
        for(int i=2;i<=n;i++)ans=(ans*i)%mod;
        cout<<ans;
    }else cout<<0;
    return 0;
}
