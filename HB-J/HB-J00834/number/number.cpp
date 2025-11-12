#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    long long a[10];
    memset(a,0,sizeof(a));
    cin >> s;
    for (long long i = 0;i < (int)s.length();i++)
    {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            a[s[i]-'0']++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        for(long long j = a[i];j > 0;j--) cout << i;
    }
    return 0;
}
