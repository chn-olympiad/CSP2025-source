#include <bits/stdc++.h>

using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int len;
int a[1005];
int  n = 0;
int change = 0;



int main()
{
    string s;
    cin >> s;
    len = s.size()-1;
    for(int i = 0;i<=len-1;i++)
    {
        if(s[i] >='0' && s[i] <= '9')
        {
            change = s[i]-'0';
            n++;
            a[n] = change;
            change = 0;

        }
    }

    sort(a+1,a+n+1);

    for(int i =n;i>=1;i--)
    {

        cout << a[i];
    }

    return 0;
}
