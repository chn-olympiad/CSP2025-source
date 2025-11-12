#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    vector<int> nums;
    map<int, int> mp;
    for(char c:s){
        if( c <= '9' && c >= '0' ){

            if(!mp[c-'0']){
                nums.push_back(c-'0');
            }
            mp[c-'0']++;
        }
    }
    sort(nums.begin(), nums.end());

    for(int i = nums.size()-1;i>=0;i--){
        for(int j=1;j<=mp[nums[i]];j++){
            cout << nums[i];
        }
    }

    return 0;
}
