#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char number[10000010],cnt=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            number[cnt]=s[i];
            cnt++;
        }
    }
    sort(number+1,number+cnt,greater<char>());
    for(int i=1;i<cnt;i++) cout << number[i];
    return 0;
}

