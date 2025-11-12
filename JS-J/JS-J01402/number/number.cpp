#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> nums;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i=0;i<s.size();i++){
        int num=0;
        if (s[i]-'0'>=0&&s[i]-'0'<=9){
            int pos=0;
            num = s[i]-'0';
            while (pos<nums.size()&&nums[pos]>num) pos++;
            nums.emplace(nums.begin()+pos,num);
        }
    }
    if (nums[0]==0){
        cout << 0;
        return 0;
    }
    for (int i=0;i<nums.size();i++){
        cout << nums[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
