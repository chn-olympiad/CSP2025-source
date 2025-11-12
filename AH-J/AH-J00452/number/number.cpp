#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,ans="";
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            ans+=s[i];
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
