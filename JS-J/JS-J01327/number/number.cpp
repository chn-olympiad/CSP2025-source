#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string ans;
    for (int i=0;i<(int)s.length();i++) {
        if (s[i]>='0' and s[i]<='9') {
            ans.push_back(s[i]);
        }
    }
    sort(ans.begin(),ans.end(),greater<char>());
    if (ans[0]=='0') {
        ans="0";
    }
    cout<<ans<<"\n";
    return 0;
}
