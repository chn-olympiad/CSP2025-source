#include <bits/stdc++.h>
using namespace std;
string s,a;
int l;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    a.resize(s.size());
    for(int i=0;i<s.size();++i)
    {
        if((s[i]<='9'&&s[i]>='0'))
        {
            a[l++]=s[i];
        }
    }
    stable_sort(a.begin(),a.end(),greater<char>());
    cout<<a;
    return 0;
}
