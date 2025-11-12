#include<bits/stdc++.h>
using namespace std;
string a;
int number[10];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        number[s[i]-'0']++;
    }
    for(int i=10-1;i>=0;i--)
    {
        while(number[i])
        {
            a+=(i+'0');
            number[i]--;
        }
    }
    cout << a << endl;
    return 0;
}
