#include <bits/stdc++.h>
using namespace std;
int book[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
        book[s[i]-48]++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=book[i];j++)
            cout << i;
    return 0;
}
