#include <bits/stdc++.h>
using namespace std;

int nums[1000008] = {}, cnt=0;
string s;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    for(int i=0; i<1000008; i++)
        nums[i] = -1;
    cin >> s;
    for(int i=0; i<s.length(); i++)
    {
        if('0' <= s[i] && '9' >= s[i])
        {
            nums[i] = s[i] - '0';
            cnt++;
        }
    }

    sort(nums+0, nums+s.length());
    if(cnt == 1)
    {
        cout << nums[s.length()-1];
        return 0;
    }
    for(int i=s.length()-1; i>=0; i--)
    {
        if(nums[i] != -1) cout << nums[i];
    }
    return 0;
}
