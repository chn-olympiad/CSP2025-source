#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    vector<int> nums;
    for(char c : s)
    {
        if(isdigit(c))
            nums.push_back(c - '0');
    }
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i];

    return 0;
}
