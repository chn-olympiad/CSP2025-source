#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
string s,ans;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) ans+=s[i];
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
    return 0;
}
