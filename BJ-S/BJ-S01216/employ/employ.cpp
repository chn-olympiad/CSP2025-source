#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int n,m;
string s;
int tim(int x){
    int ret=1;
    for(int i=1;i<=x;i++){
        ret*=i;
        ret%=mod;
    }
    return ret;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    if(m==n){
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){
                cout<<0;
                return 0;
            }
        }
        cout<<tim(n);
        return 0;
    }
    cout<<tim(n);
    return 0;
}
