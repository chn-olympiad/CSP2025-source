#include <iostream>
using namespace std;
int number[10];
int main()
{
    string s;
    int len;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    len = s.length();
    for (int i = 0;i < len;i++)
        if (s[i] >= '0' && s[i] <= '9')
            number[s[i]-48]++;
    for (int i = 9;i >= 0;i--){
        while (number[i] > 0){
            number[i]--;
            cout << i;
        }
    }
    return 0;
}
