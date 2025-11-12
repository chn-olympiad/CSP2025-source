#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    ll num=0;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end());
    if(v.empty()){
        cout<<0;
        return 0;
    }
    for(ll i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
    return 0;
}
