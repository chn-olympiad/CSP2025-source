#include <iostream>
#include <algorithm>
bool cmp(int x, int y)
{
    return x > y;
}
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int sum = 0;
    int a[1005];
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i] - '0') <= 9)
        {
            sum++;
            a[sum] = s[i] - '0';
        }
    }
    sort(a + 1, a + sum + 1, cmp);
    int ans = 0;
    for(int i = 1; i <= sum; i++)
    {
        for(int j = sum-i; j >= 1; j--)
        {
            a[i] *= 10;
        }
        ans += a[i];
    }
    cout << ans;
    return 0;
}
