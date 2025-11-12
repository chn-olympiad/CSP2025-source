#include <bits/stdc++.h>
using namespace std;

string s;
vector <int> nums;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            int x=s[i]-'0';
            nums.push_back(x);
        }
    }
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=n-1;i>=0;i--){
        cout<<nums[i];
    }
    return 0;
}
