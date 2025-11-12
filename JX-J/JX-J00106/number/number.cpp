#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto c:s)
    {
        if(c>='0'&&c<='9') a.push_back(c);
    }
    sort(a.begin(),a.end(),greater<char>());
    for(auto c:a)
    {
        cout<<int(c-'0');
    }
    return 0;
}