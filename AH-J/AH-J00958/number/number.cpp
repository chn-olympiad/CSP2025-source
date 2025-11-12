#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string s;
vector<int> v;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char ch:s)
        if(isdigit(ch))
            v.push_back(ch-'0');
    sort(v.begin(),v.end(),greater<int>());
    for(int i:v) cout<<i;
    return 0;
}
