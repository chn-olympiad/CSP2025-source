#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    vector<char> s;

    string str;
    cin>>str;

    for(int i=0;i<str.size();i++)
        if(isdigit(str[i]))
            s.push_back(str[i]);

    sort(s.begin(),s.end(),greater<char>());

    if(s.empty() || s[0]=='0')
    {
        cout<<0<<'\n';
        return 0;
    }
    for(auto i:s)
        cout<<i;
    cout<<'\n';

    return 0;
}