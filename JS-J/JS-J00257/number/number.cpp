#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    vector<int> l;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <='9')
        {
            l.push_back(s[i]-'0');
        }
    }
    sort(l.begin(), l.end(), greater<>());
    for(int i: l) cout<<i;
    cout<<"\n";
    return 0;
}
