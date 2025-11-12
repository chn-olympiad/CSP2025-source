#include <iostream>
#include <string>
using namespace std;
long long num[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if('0' <= s[i] && s[i] <= '9') num[s[i] - '0']++;
    }
    bool flag = true;
    for(int i = 9 ; i >= 1 ; i--)
    {
        if(num[i] > 0)
        {
            flag = false;
            break;
        }
    }
    if(flag == true)
    {
            cout << "0" << endl;
            return 0;
    }
    for(int i = 9 ; i >= 0 ; i--)
    {
        for(int j = 1 ; j <= num[i] ; j++) cout << i;
    }
    return 0;
} 