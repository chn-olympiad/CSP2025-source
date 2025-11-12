#include <bits/stdc++.h>
using namespace std;
int nums[(long)(1e6+3)];
long j;
string s;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (long i = 0; i < s.length(); i++)
        if (s[i] <= '9' && s[i] >= '0')
            nums[j++] = s[i] - '0';
    sort(nums, nums+j);
    while (j--)
        cout << nums[j];
    cout << endl;
    return 0;
}
