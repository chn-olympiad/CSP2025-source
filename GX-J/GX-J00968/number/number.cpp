#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int> a;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]-'0'>=0&&s[i]-'0'<=9)
        {
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end(),greater<int>() );
    for(int i=0;i<a.size();i++)
        cout<<a[i];
    return 0;
}
