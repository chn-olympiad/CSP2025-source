#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0; i<s.size(); ++i)
    {
        if('0'<=s[i] && s[i]<='9')
        {
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); ++i)
    {
        cout<<v[i];
    }
    return 0;
}
