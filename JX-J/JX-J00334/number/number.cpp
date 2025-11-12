#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector<int> nums;
int main(){
    //printf("%d%d",'0','9');
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            nums.push_back(s[i]-'0');
        }
    }
    sort(nums.begin(),nums.end());
    for(int i=nums.size()-1;i>=0;i--){
        cout<<nums[i];
    }
    return 0;
}
