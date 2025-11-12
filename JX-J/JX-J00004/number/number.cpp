#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string s,n;
int len,b;
char c;
int a[1000005];
bool cmp(char a,char b)
{
    return a<b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin >> s;
    len = s.size();
    for(int i = 0;i < len;i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            n = n+s[i];
            b++;
        }
    }
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
