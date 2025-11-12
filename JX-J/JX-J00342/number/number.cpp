#include <bits/stdc++.h>
using namespace std;
string s,luvia[100001];
long long all,pos;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<=s.length()-1;i++)
    {
        if((s[i]>='1'&&s[i]<='9')||(s[i]=='0'))
        {
            pos++;
            luvia[pos]=s[i];
        }
    }
    sort(luvia,luvia+pos+1);
    for(long long i=pos;i>=1;i--)
    {
        cout<<luvia[i];
    }
    return 0;
}
