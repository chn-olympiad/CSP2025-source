#include <bits/stdc++.h>
#define int long long
#define st first
#define nd second
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N=1e6,mod=1e9+7;
int quickpow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.rbegin(),s.rend());
    rep(i,0,s.size())if(s[i]>='0'&&s[i]<='9')cout<<s[i];
    return 0;
}
