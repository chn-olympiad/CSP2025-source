#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(auto &c:s)
        if(isdigit(c))
            ans.push_back(c-48);
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    for(auto &p:ans) cout<<p;
    return 0;
}
