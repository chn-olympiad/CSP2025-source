#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> nums;
    for(char c:s){
        if(isdigit(c)){
            nums.push_back(c-'0');
        }
    }
    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());
    if(nums[0]==0){
        cout<<0<<endl;
        return 0;
    }
    for(int a:nums){
        cout<<a;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
