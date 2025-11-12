#include<bits/stdc++.h>
using namespace std;
string s;
long long a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    char m[s.size()];
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' and s[i] <= '9')
        {
            m[a] = s[i];
            a++;
        }
    }
    sort(m,m + a,greater<char>());
    for(int i = 0;i < a;i++) cout<<m[i];
    return 0;
}
