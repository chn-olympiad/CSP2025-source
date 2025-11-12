#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[20];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(ll i=0;i<ll(s.size());i++)
        if(isdigit(s[i])) cnt[ll(s[i]-'0')]++;
    for(ll i=9;i>=0;i--)
        while(cnt[i]--) cout<<i;
    return 0;
}
