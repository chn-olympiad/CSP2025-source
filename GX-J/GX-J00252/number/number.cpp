#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int num[10005] = {};
    int w = 0;
    for (int i = 0;i <= s.size();i++)
    {
        if (s[i] == 0 || s[i] == 1 || s[i] == 2 || s[i] == 3 || s[i] == 4 || s[i] == 5 || s[i] == 6 || s[i] == 7 || s[i] == 8 || s[i] == 9)
        {
            num[i] = s[i];
            w++;
        }
    }
    sort(num+1,num+s.size()+1);
    for (int i = s.size();i >= 0;i--)
    {
        cout << num[i];
    }
    return 0;
}
