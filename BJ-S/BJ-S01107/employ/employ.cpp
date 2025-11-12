#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
const ll N=1010100,MOD=998244353;
ll cnt=0;
ll c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(ll i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
    if(m==1){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(s[i]=='1'&&c[j]>=i){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
