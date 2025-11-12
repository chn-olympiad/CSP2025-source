#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    int len = s.length();

    vector<int> nums;
    for(int i = 0;i < len;i ++){
        if(s[i] >= '0' && s[i] <= '9') nums.push_back(s[i]);
    }

    sort(nums.begin(),nums.end(),greater<int>());
    for(char c : nums) cout << c;

    return 0;
}