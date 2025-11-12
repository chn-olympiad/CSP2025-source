#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<ll>e;
    for(ll i=0;i<s.size();i++)
        if('0'<=s[i]&&s[i]<='9')
            e.push_back(s[i]-'0');
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());
    for(auto i:e)
        cout<<i;
    return 0;
}
