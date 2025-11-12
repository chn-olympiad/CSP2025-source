#include <bits/stdc++.h>
using namespace std;
string s;
vector<int>a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i])) a.push_back(s[i]-48);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0; i!=a.size(); i++) cout<<a[i];
    cout<<'\n';
    return 0;
}
