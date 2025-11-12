#include <bits/stdc++.h>
using namespace std;
string s;
bool b=true;
long long n;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    n=s.size();
    for(char i='9';i>='0';i--)
    {
        for(long long j=0;j<n;j++)
        {
            if(s[j]==i)
            {
                cout << i;
            }
        }
    }
}
