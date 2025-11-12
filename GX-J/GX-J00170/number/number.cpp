#include <bist/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if (s.size()==1) cout <<s;
    if (s.size()==2)
    {
        for (int i = 1;i<=n;i++)
        {
            if (s[i]>s[i+1]) cout <<s[i];
            else if (s[i]==s[i+1]) cout <<s[i];
            else cout <<s[i+1];
        }
    }
    return 0;
}

