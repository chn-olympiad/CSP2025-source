#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if('0'<=s[i]&&s[i]<='9')    v.push_back(s[i]-48);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)    cout<<v[i];
    return 0;
}