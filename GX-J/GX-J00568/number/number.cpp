#include <iostream>
#include <string>
using namespace std;
string s , a , max = "0";
int b;
int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> s;
    int l = 0;
    for (int i = 0;i < s.length();i++)
    {
        if(s[i] >= "0" && s[i] <= "9")
        {
            b++;
            a[l] = s[i];
            l++;
        }

    }
    for(int i = 0;i < b;i++)
    {
        for(int j = 0;j < b;j++)
        {
             if(a[j] > max)
             {
                max = a[j];
             }
        }
        cout << max;
    }
    return 0;
}
