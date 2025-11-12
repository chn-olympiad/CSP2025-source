#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int c;
ll ans=1;
ll mod=998244353;
ll cnt=0;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c==0){
            cnt++;
        }
    }
    if(n-cnt<m){
        cout<<"0";
        return 0;
    }
    for(ll i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    cout<<ans;
    return 0;
}
