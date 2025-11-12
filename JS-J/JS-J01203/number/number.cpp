#include <bits/stdc++.h>
using namespace std;

string s;
const int maxn=1000005;
int ans[maxn];
int flag=0;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();++i)
    {
        if(isdigit(s[i]))
        {
            ans[flag]=s[i]-'0';
            flag++;
        }
    }
    sort(ans,ans+flag);
    for(int i=0;i<flag;++i)
        cout<<ans[flag-i-1];
    return 0;
}
