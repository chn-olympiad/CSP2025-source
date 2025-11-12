#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[15];
string s;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (isdigit(s[i])) cnt[s[i]-'0']++;
    for (int i=9;i>=0;i--)
        for (int j=1;j<=cnt[i];j++)
            cout<<i;
    return 0;
}
