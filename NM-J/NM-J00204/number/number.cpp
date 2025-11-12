#include <bits/stdc++.h>
using namespace std;
bool cmp(char t,char u){
    return u<t;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    vector<char> nums;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0'&&str[i]<='9'){
            nums.push_back(str[i]);
        }
    }
    sort(nums.begin(),nums.end(),cmp);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<endl;
    fcloseall();
    return 0;
}
