#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
char nums[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    std::cin >> s;
    int len = 0;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            len ++;
            nums[len-1] = s[i];
        }
    }
    string res = "";
    int remains = len;
    while(remains != 0){
        int max_ = INT_MIN;
        int max_idx;
        for(int i = 0; i < len; i ++){
            if(nums[i] == 'X') continue;
            if(int(nums[i]) > max_){
                max_ = int(s[i]);
                max_idx = i;
            }
        }
        res += nums[max_idx];
        nums[max_idx] = 'X';
        remains--;
    }
    std::cout << res;
    return 0;
}
