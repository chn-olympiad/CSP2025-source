#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    string s;
    cin>>s;
    string t="";
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            t.push_back(s[i]);
        }
    }
    sort(t.begin(),t.end(),greater<>());
    cout<<t;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}