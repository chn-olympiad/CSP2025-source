#include <bits/stdc++.h>
using namespace std;

string s;
int nums[1000005], cur = 1;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            nums[cur] = s[i] - '0';
            cur++;
        }
    }
    cur--;
    sort(nums + 1, nums + cur + 1);
    for(int i = cur; i >= 1; i--)
    {
        cout << nums[i];
    }
    return 0;
}
