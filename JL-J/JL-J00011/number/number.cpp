// A
// expect pts = 100
// expect diff = red

// 缘为天定，但愿重逢。
// 感谢你 曾经出现在我的生命里。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

string str;
vector<int> nums;

bool cmp(int a, int b)
{
    return a > b;
}

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> str;
    for(int i = 0 ; i < str.size() ; i ++)
        if(isdigit(str[i]))
            nums.push_back(str[i] - '0');

    sort(nums.begin(), nums.end(), cmp);

    for(auto i : nums)
        cout << i;
    cout << endl;

    return 0;
}
