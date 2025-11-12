#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;
string s;
int cnt[15];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.length();
    for(int i = 0; i <= len - 1; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            cnt[s[i] - '0']++;
    }
    for(int i = 9; i >= 0; i--)
    {
        if(cnt[i] > 0)
        {
            for(int j = 1; j <= cnt[i]; j++) cout << i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
