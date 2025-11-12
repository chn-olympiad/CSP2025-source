#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    ll n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9')a.push_back((s[i]-'0'));
    }
    sort(a.begin(),a.end(),greater<int>());
    for(auto i:a)cout<<i;
    return 0;
}
