#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000005],cnt=1;
string s;
//vector<ll> v;
void solve(){
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-48]++;
        }
    }
    for(ll i=9;i>=0;i--){
        if(a[i]!=0){
            for(ll j=1;j<=a[i];j++) cout<<i;
        }
    }
    return ;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
