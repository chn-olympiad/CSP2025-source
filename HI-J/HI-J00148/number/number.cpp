#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a += s[i];
        }
    }
    int n = a.size();
    for (int i = 0; i < s.size(); i++)
    {
        b[i] = a[i];
    }
    sort (b,b+n);
    for (int i = a.size() - 1; i >= 0; i--)
    {
        cout<< b[i] - '0';
    }
	return 0;
}
