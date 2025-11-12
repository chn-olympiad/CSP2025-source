#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    string s;
    cin>>s;

    int l=(int)s.size();
    for(int i=0;i<l;i++){
        if('0'<=s[i] && s[i]<='9') v.push_back(int(s[i]-'0'));
    }

    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
    return 0;
}
